# AttributeCollection - Получить массив атрибутов

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [IFeature - методы ](ksfeature_methods.html) |  Scroll [ [ [ ](ksfeature_attributecollectionex.html "К следующему разделу")](ksfeature_methods.html "На уровень выше")](ksfeature_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfeature.html)

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
Numb | \- номер типа атрибута для поиска по номеру либо 0.  
  
Возвращаемое значение:

| \- указатель на массив атрибутов [ksAttribute3DCollection](ksattribute3dcollection.html).  
---|---  
  
Примечание:

Атрибут - это дополнительная неграфическая информация, связанная с объектом или несколькими объектами чертежа. Такая информация может быть представлена в виде числа, строки текста, а также таблицы с фиксированным или переменным числом строк.

В дальнейшем значения атрибутов могут использоваться для поиска объектов, а также обрабатываться различными приложениями (например, системой проектирования спецификаций, различными расчетными программами и т.п.).

Типы (описания структуры) атрибутов могут храниться как непосредственно в документе, так и в специальных файлах (библиотеках типов атрибутов). Эти файлы имеют расширение lat.

Подразделы:

(отсутствуют)
