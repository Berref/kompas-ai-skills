# GetSummMatrix - Получить суммарную матрицу преобразования координат

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](ksuserparam_libname_example.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_getplacement.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

VARIANT GetSummMatrix( LPDISPATCH part1 );

Синтаксис COM:

BOOL GetSummMatrix( VARIANT * matrix,

LPPART part1 );

Входные параметры:

part1 | \- указатель на интерфейс [ksPart](kspart.html) или [IPart](kspart.html) детали из которой нужно сделать пересчет координат.  
---|---  
  
Возвращаемое значение:

массив SafeArray типа VT_ARRAY | VT_R8 |   
---|---  
  
Примечания:

1\. Элементы матрицы возвращаются в виде одномерного массива из шестнадцати элементов.

2\. Матрица имеет размер 4х4.

Подразделы:

(отсутствуют)
