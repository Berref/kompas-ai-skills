# AttributeCollection - Получить массив атрибутов

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_changeobjectinlibrequest.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_addmateconstraint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

ksAttribute3DCollection* AttributeCollection (long key1,

long key2,

long key3,

long key4,

double numb,

LPDISPATCH pObj);

Синтаксис COM:

LPATTRIBUTE3DCOLLECTION AttributeCollection (long key1,

long key2,

long key3,

long key4,

double numb,

LPUNKNOWN pObj);

Входные параметры:

key1, key2, key3, key4 | \- ключи для поиска по ключам либо 0,  
---|---  
numb | \- номер типа атрибута для поиска по номеру либо 0,  
pObj | \- указатель на [ksDocument3D](ksdocument3d.html) \- атрибуты документа, [ksFeatureCollection](ksfeaturecollection.html) \- атрибуты для данной группы объектов, [ksFeature](ksfeature.html) \- атрибуты определенного объекта.  
  
Возвращаемое значение:

| \- указатель на массив атрибутов [ksAttribute3DCollection](ksattribute3dcollection.html).  
---|---  
  
Примечания:

Атрибут - это дополнительная неграфическая информация, связанная с объектом или несколькими объектами чертежа. Такая информация может быть представлена в виде числа, строки текста, а также таблицы с фиксированным или переменным числом строк.

В дальнейшем значения атрибутов могут использоваться для поиска объектов, а также обрабатываться различными приложениями (например, системой проектирования спецификаций, различными расчетными программами и т.п.).

Типы (описания структуры) атрибутов могут храниться как непосредственно в документе, так и в специальных файлах (библиотеках типов атрибутов). Эти файлы имеют расширение lat.

Подразделы:

(отсутствуют)
