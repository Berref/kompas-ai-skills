# GetLength - Получить общую длину ребер

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Цикл грани(Интерфейсы ksLoop, ILoop) ](ksloop.html) > [ILoop - методы ](ksloop_methods.html) |  Scroll [ [ [ ](ksloop_isouter.html "К следующему разделу")](ksloop_methods.html "На уровень выше")](ksloop_edgecollection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksloop.html)

Синтаксис Automation:

double GetLength (unsigned long bitVector);

Синтаксис COM:

double GetLength (unsigned long bitVector );

Входные параметры:

bitVector | \- единицы измерения в интервале [ST_MIX_MM..ST_MIX_M].  
---|---  
  
Возвращаемое значение:

общая длина ребер | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
