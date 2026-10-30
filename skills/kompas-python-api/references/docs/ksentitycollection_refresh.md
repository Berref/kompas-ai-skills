# Refresh - Обновить массив интерфейсов объектов трехмерной модели (осей, плоскостей и т.п.)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Массив объектов модели (Интерфейсы ksEntityCollection и IEntityCollection) ](ksentitycollection.html) > [ksEntityCollection - методы ](ksentitycollection_methods.html) |  Scroll [ [ [ ](ksentitycollection_setbyindex.html "К следующему разделу")](ksentitycollection_methods.html "На уровень выше")](ksentitycollection_prev.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksentitycollection.html)

Синтаксис Automation:

BOOL Refresh();

Синтаксис COM:

BOOL Refresh();

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

После вызова данной функции возникает полное соответствие массива в памяти с массивом точек ребра (поверхности) и удаляются все предыдущие изменения в массиве.

Подразделы:

(отсутствуют)
