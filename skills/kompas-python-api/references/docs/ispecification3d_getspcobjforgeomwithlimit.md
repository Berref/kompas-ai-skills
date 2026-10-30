# GetSpcObjForGeomWithLimit - Получить указатель на объект спецификации, подключенный к трехмерному компоненту (детали или подсборке) с ограничениями по номеру раздела и типу атрибута

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ISpecification3D ](ispecification3d.html) > [ISpecification3D - методы ](ispecification3d_methods.html) |  Scroll [ [ [ ](ispecification3d_spcincludepart.html "К следующему разделу")](ispecification3d_methods.html "На уровень выше")](ispecification3d_d3getspcobjgeometry.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecification3d.html)

Синтаксис COM:

long GetSpcObjForGeomWithLimit (LPOLESTR nameLib,

long numb,

LPPART part,

short first,

short section,

double attrTypeNumb);

Входные параметры:

nameLib | \- имя библиотеки стилей спецификации,  
---|---  
numb | \- номер стиля спецификации в библиотеке,  
part | \- указатель на интерфейс добавляемого компонента [IPart](kspart.html),  
first | \- 1 - первый объект, 0 - следующий объект,  
section | \- номер раздела, в котором нужно найти объект (0 - номер не ограничивается),  
attrTypeNumb | \- номер типа атрибута, для которого нужно найти объект (0 - номер не ограничивается).  
  
Возвращаемое значение:

| \- указатель на объект спецификации.  
---|---  
  
Синтаксис Automation:

[D3GetSpcObjForGeomWithLimit](ksspecification_d3getspcobjforgeomwithlimit.html)

Подразделы:

(отсутствуют)
