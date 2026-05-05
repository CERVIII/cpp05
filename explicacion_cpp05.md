# Explicación del Proyecto C++ Módulo 05

Este documento sirve como guía para entender y defender los conceptos clave de cada ejercicio del Módulo 05. El tema central es el manejo de **Excepciones** y la **Burocracia** (grados, formularios, firmas).

---

## ex00: Mommy, when I grow up, I want to be a bureaucrat!

### Concepto Principal
**Excepciones (`try`, `catch`, `throw`)**: En lugar de devolver códigos de error (como -1 o NULL), C++ usa excepciones para manejar situaciones anómalas. Esto separa el código de lógica principal del código de manejo de errores.

### Clases Clave
*   **`Bureaucrat`**: Representa a un burócrata.
    *   **Atributos**: `const name` (nombre) y `grade` (grado).
    *   **Grado**: Rango de 1 (más alto) a 150 (más bajo). Si intentas poner un grado fuera de este rango (al construir o al incrementar/decrementar), debe lanzar una excepción.
    *   **Excepciones**: Clases anidadas `Bureaucrat::GradeTooHighException` y `Bureaucrat::GradeTooLowException` que heredan de `std::exception`.

### Requerimientos Específicos
*   Implementar la forma canónica de Coplien (Constructor, Copy Constructor, Assignment Operator, Destructor).
*   Sobrecarga del operador `<<` para imprimir algo como: *"Juan, bureaucrat grade 2"*.
*   `incrementGrade()` debe **restar** 1 al valor numérico (1 es más alto).
*   `decrementGrade()` debe **sumar** 1 al valor numérico (150 es más bajo).

### Ejemplo de Uso
```cpp
try {
    Bureaucrat bob("Bob", 2);
    bob.incrementGrade(); // Pasa a grado 1
    bob.incrementGrade(); // Lanza GradeTooHighException (1 -> 0 no permitido)
} catch (std::exception &e) {
    std::cout << e.what() << std::endl;
}
```

---

## ex01: Form up, maggots!

### Concepto Principal
**Interacción entre clases**: Ahora las clases interactúan. Un `Bureaucrat` tiene que firmar un `Form`. Se introduce el concepto de permisos: se necesita un grado para firmar y otro para ejecutar.

### Clases Clave
*   **`Form`**: Representa un documento burocrático.
    *   **Atributos**: `const name`, `bool isSigned`, `const gradeToSign`, `const gradeToExecute`.
    *   **`beSigned(Bureaucrat)`**: Método que cambia `isSigned` a `true` si el grado del burócrata es suficiente (menor o igual al `gradeToSign`). Si no, lanza `GradeTooLowException`.
    *   **`Bureaucrat::signForm(Form)`**: El burócrata intenta firmar el formulario. Si tiene éxito, imprime un mensaje; si falla (captura la excepción del formulario), imprime la razón de error.

### Requerimientos Específicos
*   Los atributos de grado en `Form` son constantes, deben inicializarse en el constructor.
*   Getters para todos los atributos.
*   Sobrecarga de `<<` para imprimir info del formulario (nombre, estado de firma, grados requeridos).

---

## ex02: No, you need form 28B, not 28C...

### Concepto Principal
**Clases Abstractas y Herencia Polimórfica**: La clase base ahora es abstracta (no se puede instanciar directamente) y tiene un método virtual puro (`execute`).

### Clases Clave
*   **`AForm` (Abstract Form)**: Renombrar `Form` a `AForm`. Añadir método virtual puro `execute(Bureaucrat const & executor) const`.
*   **Formularios Concretos**:
    1.  **`ShrubberyCreationForm`**: (Sign: 145, Exec: 137). Crea un archivo `<target>_shrubbery` con arte ASCII de árboles.
    2.  **`RobotomyRequestForm`**: (Sign: 72, Exec: 45). Hace ruidos de taladro y tiene un 50% de probabilidad de "robotomizar" al objetivo.
    3.  **`PresidentialPardonForm`**: (Sign: 25, Exec: 5). Informa que el objetivo ha sido perdonado por Zaphod Beeblebrox.

### Requerimientos Específicos
*   **`execute(Bureaucrat)`**: Debe verificar:
    1.  Que el formulario esté firmado.
    2.  Que el ejecutor tenga el grado suficiente.
    *   Si no cumple, lanza excepción (`FormNotSignedException` o `GradeTooLowException`).
*   **`Bureaucrat::executeForm(AForm)`**: Intenta ejecutar el formulario y reporta éxito o error.

---

## ex03: At least this beats coffee-making

### Concepto Principal
**El patrón Factory (Intern)**: Un "becario" (Intern) que no tiene nombre ni grado, pero sirve para crear formularios de manera dinámica.

### Clases Clave
*   **`Intern`**:
    *   **`makeForm(std::string formName, std::string target)`**: Recibe el nombre del formulario (ej: "robotomy request") y el objetivo.
    *   Devuelve un puntero a un nuevo objeto `AForm*` (ej: `new RobotomyRequestForm(target)`).
    *   Si el nombre no existe, imprime un mensaje de error y podría devolver NULL o lanzar excepción (el subject dice "imprime mensaje de error explícito").

### Requerimientos Específicos
*   Evitar un bosque de `if/else if/else`. Lo ideal es usar un **array de punteros a funciones miembro** o un array de estructuras que asocien el nombre (string) con la función de creación.
*   El `Intern` crea el formulario y devuelve el puntero para que un `Bureaucrat` lo firme y ejecute después.

### Ejemplo de Uso (Intern)
```cpp
Intern someRandomIntern;
AForm* rrf;
rrf = someRandomIntern.makeForm("robotomy request", "Bender");
if (rrf) {
    Bureaucrat boss("Boss", 1);
    boss.signForm(*rrf);
    boss.executeForm(*rrf);
    delete rrf; // Importante limpiar memoria
}
```

---

## Leyenda / Glosario de Términos

Aquí tienes una explicación rápida de las palabras clave y conceptos que usamos en este proyecto:

*   **`try`**: Significa "intentar". Es un bloque de código donde ponemos las operaciones que podrían fallar (lanzar una excepción). Si algo malo pasa ahí dentro, el flujo salta al bloque `catch`.
*   **`catch`**: Significa "atrapar" o "capturar". Es el bloque que recibe el error si algo falló en el `try`. Aquí es donde manejas el error (imprimes un mensaje, cierras archivos, etc.) para que el programa no se rompa (crash).
*   **`throw`**: Significa "lanzar". Es la palabra clave para generar un error manualmente. Ej: `throw GradeTooHighException();` es como decir "¡Hey, ha ocurrido un error de grado muy alto!". Detiene la ejecución normal y busca un `catch`.
*   **`exception`**: Es la clase base estándar de C++ para todos los errores. Nuestras excepciones personalizadas (como `GradeTooHighException`) heredan de ella para ser compatibles con el sistema.
*   **`what()`**: Es un método de la clase `exception` que devuelve una cadena de texto (string) explicando qué pasó. Cuando haces `e.what()`, estás preguntando "¿Qué error fue este?".
*   **`virtual`**: Palabra clave que permite el **polimorfismo**.
    *   En métodos: Permite que una clase hija sobrescriba (`override`) el comportamiento de la clase padre.
    *   En destructores (`virtual ~Clase()`): Asegura que se llame al destructor correcto (el de la hija) cuando borras un objeto a través de un puntero a la clase padre. ¡Fundamental para evitar fugas de memoria!
*   **Clase Abstracta**: Una clase que tiene al menos un método virtual puro (`= 0`). No se pueden crear objetos de ella directamente (no puedes hacer `new AForm()`), solo sirve como base para otras clases.


---

## ¿Qué es y para qué sirve una Clase Abstracta?

Una **Clase Abstracta** es como un "plano incompleto" o un "esqueleto" de una clase.

### 1. ¿Qué es? (Técnicamente)
Es una clase que tiene al menos un **método virtual puro**.
Un método virtual puro se escribe poniendo `= 0` al final, así:
```cpp
virtual void execute(Bureaucrat const & executor) const = 0;
```
Esto le dice al compilador: *"Yo (la clase padre) no sé cómo hacer esta acción, pero obligo a mis hijos a que ellos sí definan cómo se hace".*

**Regla de oro:** **NO se pueden crear objetos (instancias) de una clase abstracta.**
```cpp
AForm formulario; // ¡Error de compilación! No puedes tener un "Formulario Abstracto".
```

### 2. ¿Para qué sirve? (En tu proyecto `AForm`)

Tiene tres utilidades principales en tu proyecto:

1.  **Evitar el "Formulario Genérico":**
    En la vida real no existe un "Formulario" a secas; existen formularios de impuestos, de multas, de perdón, etc.
    Al hacer `AForm` abstracta, impides que alguien cree un formulario que no sea de un tipo específico. Obligas a que siempre sea un `Shrubbery`, `Robotomy` o `Presidential`.

2.  **Definir un Contrato (Interfaz):**
    Garantizas que **cualquier** formulario nuevo que crees en el futuro tendrá ciertos métodos (como `beSigned` o `execute`). Si creas una clase hija y se te olvida implementar el método `execute`, el código no compilará. Es una forma de seguridad.

3.  **Polimorfismo (La clave):**
    Permite que el `Bureaucrat` y el `Intern` trabajen con `AForm*` genéricos sin saber qué tipo específico son.
    *   El `Intern` devuelve un `AForm*`.
    *   El `Bureaucrat` ejecuta un `AForm&`.
    El burócrata solo sabe que "es un formulario y se puede ejecutar", no necesita saber si va a plantar árboles o a perdonar a alguien. El código se vuelve mucho más limpio y flexible.
