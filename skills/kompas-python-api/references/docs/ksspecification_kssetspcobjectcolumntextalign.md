# ksSetSpcObjectColumnTextAlign - Установить выравнивание для текста колонки объекта спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_kssetspcperformancename.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_kssetspcobjectcolumntextex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksSetSpcObjectColumnTextAlign](kssetspcobjectcolumntextalign.html).

Синтаксис Automation:

BOOL ksSetSpcObjectColumnTextAlign ( long spcObj,

long columnNumber,

long lineIndex,

long align );

Входной параметр:

spcObj | \- указатель на объект спецификации.  
---|---  
columnNumber | \- номер колонки, начиная с 1,  
lineIndex | \- индекс строки текста,  
align | \- выравнивание.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

Значение переменной align может принимать значения:

0 - Выравнивание влево;

1 - Выравнивание по центру;

2 - Выравнивание вправо;

3 - Выравнивание по ширине.

Подразделы:

(отсутствуют)
