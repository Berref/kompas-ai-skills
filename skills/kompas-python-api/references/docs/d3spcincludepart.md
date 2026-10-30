# D3SpcIncludePart - Добавить или изменить трехмерный компонент (деталь или подсборку) в объекте спецификации

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksaddspcdescription.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](d3getspcobjforgeomwithlimit.html "К предыдущему разделу")  
---|---  
  
Аналог данного метода при использовании Automation - метод [D3SpcIncludePart](ksspecification_d3spcincludepart.html).

Синтаксис:

BOOL D3SpcIncludePart (LPDISPATCH part, BOOL fillTexts);

Входные параметры:

part | \- указатель на интерфейс компонента [ksPart](kspart.html),  
---|---  
fillTexts | \- признак автоматического заполнения: наименование, обозначение, масса из свойств ksPart: TRUE - автозаполнение включено, FALSE - выключено.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
