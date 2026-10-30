# EntityCollection - Получить указатель на интерфейс динамического массива объектов заданного типа, выбранных в документе

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_excludefeaturesafter.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_deleteobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

LPDISPATCH EntityCollection (short objType, BOOL checkEntity);

Синтаксис COM:

LPENTITYCOLLECTION EntityCollection (short objType,BOOL checkEntity);

Входные параметры:

objType | \- [тип объектов](obj3dtype.html), содержащихся в массиве,  
---|---  
checkEntity | \- признак проверки для вновь добавляемых объектов на NULL (TRUE - проверка включена, FALSE - проверка выключена и в массив можно добавить NULL).  
  
Возвращаемое значение:

| \- указатель на интерфейс динамического массива объектов ksEntityCollection или [IEntityCollection](ksentitycollection.html).  
---|---  
  
Примечание:

Массив создается пустым. Метод[ Refresh](ksentitycollection_refresh.html) для полученного массива не работает.

Подразделы:

(отсутствуют)
