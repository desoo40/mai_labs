// Этот пример поможет узнать о различных элементах языка F#.  
//
// *******************************************************************************************************
//   Чтобы выполнить код в интерактивном режиме F#, выделите фрагмент кода и нажмите ALT+ВВОД или щелкните правой кнопкой мыши 
//   и выберите команду "Выполнение в интерактивном режиме".  Интерактивное окно F# можно также открыть из меню "Вид". 
// *******************************************************************************************************
//
// Дополнительные сведения о F# см. по адресу:
//     http://fsharp.org
//
// Дополнительные шаблоны, которые можно использовать с F#, см. в разделе "Шаблоны в Интернете" в Visual Studio.
//     "Создать проект --> Шаблоны в Интернете"
//
// Отдельные темы по F# см. по адресу:
//     http://go.microsoft.com/fwlink/?LinkID=234174 (портал разработчиков на F#)
//     http://go.microsoft.com/fwlink/?LinkID=124614 (галерея кода)
//     http://go.microsoft.com/fwlink/?LinkId=235173 (математическое и статистическое программирование)
//     http://go.microsoft.com/fwlink/?LinkId=235176 (работа с диаграммами)

// Содержание:
//    - Целые значения и базовые функции
//    - Логические значения
//    - Строки
//    - Кортежи
//    - Списки и обработка списков
//    - Классы
//    - Универсальные классы
//    - Реализация интерфейсов
//    - Массивы
//    - Последовательности
//    - Рекурсивные функции
//    - Типы записей
//    - Типы объединений
//    - Типы параметров            
//    - Регулярные выражения        
//    - Единицы измерения        
//    - Программирование параллельных массивов
//    - Использование событий
//    - Обращение к базам данных с помощью поставщиков типов
//    - Обращение к OData с помощью поставщиков типов



// ---------------------------------------------------------------
//         Целые значения и базовые функции
// ---------------------------------------------------------------

module Integers = 
    let sampleInteger = 176

    /// Выполнение арифметических действий, начиная с первого целого числа
    let sampleInteger2 = (sampleInteger/4 + 5 - 7) * 4

    /// Список чисел от 0 до 99
    let sampleNumbers = [ 0 .. 99 ]

    /// Список всех кортежей, содержащих все числа от 0 до 99 и их квадраты
    let sampleTableOfSquares = [ for i in 0 .. 99 -> (i, i*i) ]

    // Следующая строка печатает список, который включает кортежи, используя %A для универсальной печати
    printfn "The table of squares from 0 to 99 is:\n%A" sampleTableOfSquares


module BasicFunctions = 

    // let служит для определения функции, которая принимает целочисленный аргумент и возвращает целое число. 
    let func1 x = x*x + 3             

    // Использовать скобки для аргументов функций необязательно
    let func1a (x) = x*x + 3             

    /// Применяйте функции, именуя возвращаемый функцией результат с помощью let. 
    /// Тип переменной определяется возвращаемым типом функции.
    let result1 = func1 4573
    printfn "The result of squaring the integer 4573 and adding 3 is %d" result1

    // При необходимости аннотируйте тип имени параметра с помощью конструкции "(argument:type)"
    let func2 (x:int) = 2*x*x - x/5 + 3

    let result2 = func2 (7 + 4)
    printfn "The result of applying the 1st sample function to (7 + 4) is %d" result2

    let func3 x = 
        if x < 100.0 then 
            2.0*x*x - x/5.0 + 3.0
        else 
            2.0*x*x + x/5.0 - 37.0

    let result3 = func3 (6.5 + 4.5)
    printfn "The result of applying the 2nd sample function to (6.5 + 4.5) is %f" result3



// ---------------------------------------------------------------
//         Логические значения
// ---------------------------------------------------------------

module SomeBooleanValues = 

    let boolean1 = true
    let boolean2 = false

    let boolean3 = not boolean1 && (boolean2 || false)

    printfn "The expression 'not boolean1 && (boolean2 || false)' is %A" boolean3



// ---------------------------------------------------------------
//         Строки
// ---------------------------------------------------------------

module StringManipulation = 

    let string1 = "Hello"
    let string2  = "world"

    /// Используйте @ для создания строковых литералов verbatim
    let string3 = @"c:\Program Files\"

    /// С помощью строкового литерала тройной кавычки
    let string4 = """He said "hello world" after you did"""
    printfn "%s" string4

    let helloWorld = string1 + " " + string2 // объедините две строки, поместив пробел между ними
    printfn "%s" helloWorld

    /// Строка, образованная из первых 7 символов одной из результирующих строк
    let substring = helloWorld.[0..6]
    printfn "%s" substring



// ---------------------------------------------------------------
//         Кортежи (упорядоченные наборы значений)
// ---------------------------------------------------------------

module Tuples = 

    /// Простой кортеж целых
    let tuple1 = (1, 2, 3)

    /// Функция, меняющая местами два значения в кортеже. 
    /// Краткие сведения показывают, что функцию имеет универсальный тип.
    let swapElems (a, b) = (b, a)

    printfn "The result of swapping (1, 2) is %A" (swapElems (1,2))

    /// Кортеж, состоящий из целого числа, строки и числа с плавающей запятой двойной точности
    let tuple2 = (1, "fred", 3.1415)

    printfn "tuple1: %A    tuple2: %A" tuple1 tuple2
    


// ---------------------------------------------------------------
//         Списки и обработка списков
// ---------------------------------------------------------------

module Lists = 

    let list1 = [ ]            /// пустой список

    let list2 = [ 1; 2; 3 ]    /// список из трех элементов

    let list3 = 42 :: list2    /// новый список, в начало которого добавлено значение "42"

    let numberList = [ 1 .. 1000 ]  /// список целых значений от 1 до 1000

    /// Список, содержащий все дни года
    let daysList = 
        [ for month in 1 .. 12 do
              for day in 1 .. System.DateTime.DaysInMonth(2012, month) do 
                  yield System.DateTime(2012, month, day) ]

    /// Список, содержащий кортежи, представляющие собой координаты черных клеток шахматной доски.
    let blackSquares = 
        [ for i in 0 .. 7 do
              for j in 0 .. 7 do 
                  if (i+j) % 2 = 1 then 
                      yield (i, j) ]

    /// Возведение в квадрат чисел из numberList; аргументы передаются в List.map с помощью конвейерного оператора    
    let squares = 
        numberList 
        |> List.map (fun x -> x*x) 

    /// Вычисление суммы квадратов чисел, кратных 3.
    let sumOfSquares = 
        numberList
        |> List.filter (fun x -> x % 3 = 0)
        |> List.sumBy (fun x -> x * x)



// ---------------------------------------------------------------
//         Классы
// ---------------------------------------------------------------

module DefiningClasses = 

    /// Конструктор класса принимает два аргумента dx и dy, которые оба имеют тип float. 
    type Vector2D(dx : float, dy : float) = 
        /// Длина вектора, вычисляемая при создании объекта
        let length = sqrt (dx*dx + dy*dy)

        // Ключевое слово this задает имя идентификатора самого объекта.
        // В методах экземпляров оно должно находиться перед именем члена.
        member this.DX = dx  

        member this.DY = dy

        member this.Length = length

        member this.Scale(k) = Vector2D(k * this.DX, k * this.DY)
    
    /// Экземпляр класса Vector2D
    let vector1 = Vector2D(3.0, 4.0)

    /// Получение нового объекта масштабированного объекта без изменения исходного объекта 
    let vector2 = vector1.Scale(10.0)

    printfn "Length of vector1: %f      Length of vector2: %f" vector1.Length vector2.Length



// ---------------------------------------------------------------
//         Универсальные классы
// ---------------------------------------------------------------

module DefiningGenericClasses = 

    type StateTracker<'T>(initialElement: 'T) = // 'T - параметр типа для класса

        /// Сохранять состояния в списке
        let mutable states = [ initialElement ]

        /// Добавление нового элемента в список состояний
        member this.UpdateState newState = 
            states <- newState :: states  // Оператор "<-" служит для изменения значения

        /// Получение полного списка исторических состояний
        member this.History = states

        /// Получение последнего состояния
        member this.Current = states.Head

    /// Экземпляр int класса отслеживания состояний. Обратите внимание, что параметр типа подразумевается.
    let tracker = StateTracker 10

    // Добавление состояния
    tracker.UpdateState 17



// ---------------------------------------------------------------
//         Реализация интерфейсов
// ---------------------------------------------------------------

/// Тип, реализующий IDisposable
type ReadFile() =

    let file = new System.IO.StreamReader("readme.txt")

    member this.ReadLine() = file.ReadLine()

    // Реализация членов IDisposable данного класса
    interface System.IDisposable with    
        member this.Dispose() = file.Close()



// ---------------------------------------------------------------
//         Массивы
// ---------------------------------------------------------------

module Arrays = 

    /// Пустой массив
    let array1 = [| |]

    let array2 = [| "hello"; "world"; "and"; "hello"; "world"; "again" |]

    let array3 = [| 1 .. 1000 |]

    /// Массив, содержащий только слова "hello" и "world"
    let array4 = [| for word in array2 do
                        if word.Contains("l") then 
                            yield word |]

    /// Массив, инициализируемый по индексу и содержащий четные числа от 0 до 2000
    let evenNumbers = Array.init 1001 (fun n -> n * 2) 

    /// подмассив, полученный с помощью нотации выделения фрагмента
    let evenNumbersSlice = evenNumbers.[0..500]

    for word in array4 do 
        printfn "word: %s" word

    // изменение элемента массива с помощью оператора присваивания в виде стрелки влево
    array2.[1] <- "WORLD!"

    /// Вычисление суммы длин слов, начинающихся на букву "h"
    let sumOfLengthsOfWords = 
        array2
        |> Array.filter (fun x -> x.StartsWith "h")
        |> Array.sumBy (fun x -> x.Length)



// ---------------------------------------------------------------
//         Последовательности
// ---------------------------------------------------------------

module Sequences = 
    // Последовательности вычисляются по требованию и заново вычисляются при каждом их переборе. 
    // Последовательность F# представляет собой экземпляр System.Collections.Generic.IEnumerable<'T>,
    // поэтому функции Seq также можно применять к спискам и массивам.

    /// Пустая последовательность
    let seq1 = Seq.empty

    let seq2 = seq { yield "hello"; yield "world"; yield "and"; yield "hello"; yield "world"; yield "again" }

    let numbersSeq = seq { 1 .. 1000 }

    /// Еще один массив, содержащий только слова "hello" и "world"
    let seq3 = 
        seq { for word in seq2 do
                  if word.Contains("l") then 
                      yield word }

    let evenNumbers = Seq.init 1001 (fun n -> n * 2) 

    let rnd = System.Random()

    /// Бесконечная последовательность, представляющая случайное блуждание
    //  yield! служит для возврата каждого элемент подпоследовательности по аналогии с IEnumerable.SelectMany.
    let rec randomWalk x =
        seq { yield x
              yield! randomWalk (x + rnd.NextDouble() - 0.5) }

    let first100ValuesOfRandomWalk = 
        randomWalk 5.0 
        |> Seq.truncate 100
        |> Seq.toList



// ---------------------------------------------------------------
//         Рекурсивные функции
// ---------------------------------------------------------------

module RecursiveFunctions  = 
              
    /// Вычисление факториала целого числа. Рекурсивная функция определяется с помощью "let rec"
    let rec factorial n = 
        if n = 0 then 1 else n * factorial (n-1)

    /// Вычисление наибольшего общего делителя двух целых чисел. 
    //  Поскольку все рекурсивные вызовы являются "хвостовыми вызовами", компилятор преобразует функцию в цикл,
    //  что повысит производительность и снизит потребление памяти.
    let rec greatestCommonFactor a b =                       
        if a = 0 then b
        elif a < b then greatestCommonFactor a (b - a)           
        else greatestCommonFactor (a - b) b

    /// Вычисление суммы списка целых значений с помощью рекурсии.
    let rec sumList xs =
        match xs with
        | []    -> 0
        | y::ys -> y + sumList ys

    /// Преобразование "хвоста" функции в рекурсию за счет вспомогательной функции, накапливающей результат
    let rec private sumListTailRecHelper accumulator xs =
        match xs with
        | []    -> accumulator
        | y::ys -> sumListTailRecHelper (accumulator+y) ys

    let sumListTailRecursive xs = sumListTailRecHelper 0 xs



// ---------------------------------------------------------------
//         Типы записей
// ---------------------------------------------------------------

module RecordTypes = 

    // определение типа записи
    type ContactCard = 
        { Name     : string;
          Phone    : string;
          Verified : bool }
              
    let contact1 = { Name = "Alf" ; Phone = "(206) 555-0157" ; Verified = false }

    // создание новое записи, которая является копией contact1, 
    // но имеет другие значения полей "Phone" и "Verified"
    let contact2 = { contact1 with Phone = "(206) 555-0112"; Verified = true }

    /// Преобразует объект ContactCard в строку
    let showCard c = 
        c.Name + " Phone: " + c.Phone + (if not c.Verified then " (unverified)" else "")
        


// ---------------------------------------------------------------
//         Типы объединений
// ---------------------------------------------------------------

module UnionTypes = 

    /// Представляет масть игральной карты
    type Suit = 
        | Hearts 
        | Clubs 
        | Diamonds 
        | Spades

    /// Представляет достоинство игральной карты
    type Rank = 
        /// Представляет достоинство карт 2 .. 10
        | Value of int
        | Ace
        | King
        | Queen
        | Jack
        static member GetAllRanks() = 
            [ yield Ace
              for i in 2 .. 10 do yield Value i
              yield Jack
              yield Queen
              yield King ]
                                   
    type Card =  { Suit: Suit; Rank: Rank }
              
    /// Возвращает представление всех карт в колоде в виде списка
    let fullDeck = 
        [ for suit in [ Hearts; Diamonds; Clubs; Spades] do
              for rank in Rank.GetAllRanks() do 
                  yield { Suit=suit; Rank=rank } ]

    /// Преобразует объект Card в строку
    let showCard c = 
        let rankString = 
            match c.Rank with 
            | Ace -> "Ace"
            | King -> "King"
            | Queen -> "Queen"
            | Jack -> "Jack"
            | Value n -> string n
        let suitString = 
            match c.Suit with 
            | Clubs -> "clubs"
            | Diamonds -> "diamonds"
            | Spades -> "spades"
            | Hearts -> "hearts"
        rankString  + " of " + suitString

    let printAllCards() = 
        for card in fullDeck do 
            printfn "%s" (showCard card)



// ---------------------------------------------------------------
//         Типы параметров
// ---------------------------------------------------------------

module OptionTypes = 
    /// Опциональные значения - это любой тип значений, отмеченных ключевым словом Some или None.
    /// Они широко используются в коде F# для представления случаев, когда во многих
    /// других языках используются пустые ссылки.

    type Customer = { zipCode : decimal option }

    /// Абстрактный класс, определяющий зону доставки по почтовому индексу заказчика 
    /// при заданных реализациях абстрактных методов getState и getShippingZone.
    [<AbstractClass>]
    type ShippingCalculator =
        abstract getState : decimal -> string option
        abstract getShippingZone : string -> int

        /// Возврат зоны доставки, соответствующей почтовому индексу заказчика
        /// У заказчика может еще не быть почтового индекса или индекс может быть недействительным
        member this.customerShippingZone(customer : Customer) =
            customer.zipCode |> Option.bind this.getState |> Option.map this.getShippingZone



// ---------------------------------------------------------------
//         Регулярные выражения
// ---------------------------------------------------------------

module PatternMatching = 

    /// Запись с именем и фамилией человека
    type Person = {     
        First : string
        Last  : string
    }

    /// определение размеченного объединения трех различных типов сотрудников
    type Employee = 
        | Engineer  of Person
        | Manager   of Person * list<Employee>            // у менеджера есть список отчетов
        | Executive of Person * list<Employee> * Employee // у руководителя также имеется помощник

    /// подсчет всех, кто находится ниже сотрудника в иерархии, включая самого сотрудника
    let rec countReports(emp : Employee) = 
        1 + match emp with
            | Engineer(id) -> 
                0
            | Manager(id, reports) -> 
                reports |> List.sumBy countReports 
            | Executive(id, reports, assistant) ->
                (reports |> List.sumBy countReports) + countReports assistant


    /// поиск всех менеджеров и руководителей по имени Dave, не имеющих отчетов
    let rec findDaveWithOpenPosition(emps : Employee list) =
        emps 
        |> List.filter(function 
                       | Manager({First = "Dave"}, []) -> true       // [] соответствует пустому списку
                       | Executive({First = "Dave"}, [], _) -> true
                       | _ -> false)                                 // "_" - подстановочный знак, обозначающий любой набор символов
                                                                     // обрабатывает вариант "иначе"



// ---------------------------------------------------------------
//         Единицы измерения
// ---------------------------------------------------------------

module UnitsOfMeasure = 

    // При применении арифметических операций F# к числовым типам код можно аннотировать с использованием единиц измерения

    open Microsoft.FSharp.Data.UnitSystems.SI.UnitNames

    [<Measure>]
    type mile =
        /// Коэффициент перевода миль в метры: метр определен в SI.UnitNames
        static member asMeter = 1600.<meter/mile>

    let d  = 50.<mile>          // Расстояние в английских единицах
    let d2 = d * mile.asMeter   // То же расстояние, выраженное в метрической системе

    printfn "%A = %A" d d2
    // let error = d + d2       // Ошибка компиляции: несоответствие единиц измерения



// ---------------------------------------------------------------
//         Программирование параллельных массивов
// ---------------------------------------------------------------

module ParallelArrayProgramming = 
              
    let oneBigArray = [| 0 .. 100000 |]
    
    // Некоторые вычисления, сильно загружающие процессор 
    let rec computeSomeFunction x = 
        if x <= 2 then 1 
        else computeSomeFunction (x - 1) + computeSomeFunction (x - 2)
       
    // Параллельное сопоставление по большому входному массиву
    let computeResults() = oneBigArray |> Array.Parallel.map (fun x -> computeSomeFunction (x % 20))

    printfn "Parallel computation results: %A" (computeResults())



// ---------------------------------------------------------------
//         Использование событий
// ---------------------------------------------------------------

module Events = 

    open System

    // создание экземпляра объекта Event, состоящего из точки подписки (event.Publish) и триггера события (event.Trigger)
    let simpleEvent = new Event<int>() 

    // добавление обработчика
    simpleEvent.Publish.Add(
        fun x -> printfn "this is handler was added with Publish.Add: %d" x)

    // срабатывание события
    simpleEvent.Trigger(5)

    // создание экземпляра Event в соответствии со стандартом .NET: (sender, EventArgs)
    let eventForDelegateType = new Event<EventHandler, EventArgs>()    

    // добавление обработчика
    eventForDelegateType.Publish.AddHandler(
        EventHandler(fun _ _ -> printfn "this is handler was added with Publish.AddHandler"))

    // срабатывание события (обратите внимание, что необходимо задать аргумент отправителя)
    eventForDelegateType.Trigger(null, EventArgs.Empty)



// ---------------------------------------------------------------
//         Обращение к базам данных с помощью поставщиков типов
// ---------------------------------------------------------------

module DatabaseAccess = 
              
    // Самый простой способ обращения к базам данных SQL с помощью F# - использовать поставщики типов F#. 
    // Добавление ссылок на System.Data, System.Data.Linq и FSharp.Data.TypeProviders.dll.
    // Для сборки объекта ConnectionString можно использовать обозреватель сервера. 

    (*
    #r "System.Data"
    #r "System.Data.Linq"
    #r "FSharp.Data.TypeProviders"

    open Microsoft.FSharp.Data.TypeProviders
    
    type SqlConnection = SqlDataConnection<ConnectionString = @"Data Source=.\sqlexpress;Initial Catalog=tempdb;Integrated Security=True">
    let db = SqlConnection.GetDataContext()

    let table = 
        query { for r in db.Table do
                select r }
    *)


    // Вместо SqlDataConnection можно также использовать SqlEntityConnection, что позволяет получать доступ к базе данных, используя платформу Entity Framework.

    ()



// ---------------------------------------------------------------
//         Обращение к OData с помощью поставщиков типов
// ---------------------------------------------------------------

module OData = 

    (*
    open System.Data.Services.Client
    open Microsoft.FSharp.Data.TypeProviders

    // Использование службы OData с данными о населении и доходах из Azure Marketplace. 
    // Дополнительные сведения см. по адресу http://go.microsoft.com/fwlink/?LinkId=239712
    type Demographics = Microsoft.FSharp.Data.TypeProviders.ODataService<ServiceUri = "https://api.datamarket.azure.com/Esri/KeyUSDemographicsTrial/">
    let ctx = Demographics.GetDataContext()

    // Вход с использованием учетной записи Azure Marketplace на сайт https://datamarket.azure.com/account/info
    ctx.Credentials <- System.Net.NetworkCredential ("<your liveID>", "<your Azure Marketplace Key>")

    let cities = query {
        for c in ctx.demog1 do
        where (c.StateName = "Washington")
        } 

    for c in cities do
        printfn "%A - %A" c.GeographyId c.PerCapitaIncome2010.Value
    *)

    ()



#if COMPILED
module BoilerPlateForForm = 
    [<System.STAThread>]
    do ()
    do System.Windows.Forms.Application.Run()
#endif
