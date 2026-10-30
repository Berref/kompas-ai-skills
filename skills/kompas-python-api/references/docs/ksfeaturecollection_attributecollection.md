# AttributeCollection - Получить массив атрибутов

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Массив объектов Дерева построения (Интерфейсы ksFeatureCollection, IFeatureCollection) ](ksfeaturecollection.html) > [ksFeatureCollection - методы ](ksfeaturecollection_methods.html) |  Scroll [ [ [ ](ksfeaturecollection_clear.html "К следующему разделу")](ksfeaturecollection_methods.html "На уровень выше")](ksfeaturecollection_addbefore.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfeaturecollection.html)

Синтаксис Automation:

ksAttribute3DCollection* AttributeCollection (long key1,

long key2,

long key3,

long key4,

double numb);

Синтаксис COM:

LPATTRIBUTE3DCOLLECTION AttributeCollection (long key1,

long key2,

long key3,

long key4,

double numb);

Входные параметры:

key1, key2, key3, key4 | \- ключи для поиска по ключам либо 0,  
---|---  
numb | \- номер типа атрибута для поиска по номеру либо 0.  
  
Возвращаемое значение:

Указатель на массив атрибутов [ksAttribute3DCollection](ksattribute3dcollection.html) |   
---|---  
  
Примечание:

Атрибут - это дополнительная неграфическая информация, связанная с объектом или несколькими объектами чертежа. Такая информация может быть представлена в виде числа, строки текста, а также таблицы с фиксированным или переменным числом строк.

Значения атрибутов могут использоваться для поиска объектов, а также обрабатываться различными приложениями, например, системой проектирования спецификаций, различными расчетными программами и т.п.

Типы (описания структуры) атрибутов могут храниться как непосредственно в документе, так и в специальных файлах - библиотеках типов атрибутов. Эти файлы имеют расширение lat.

[Структура параметров табличного атрибута](structattribute.html).

Подразделы:

(отсутствуют)
