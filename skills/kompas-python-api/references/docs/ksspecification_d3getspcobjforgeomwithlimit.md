# D3GetSpcObjForGeomWithLimit - Получить указатель на объект спецификации, подключенный к трехмерному компоненту (детали или подсборке) с ограничениями по номеру раздела и типу атрибута

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_d3getspcobjgeometry.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [D3GetSpcObjForGeomWithLimit](d3getspcobjforgeomwithlimit.html).

Синтаксис Automation:

long D3GetSpcObjForGeomWithLimit (LPCTSTR nameLib,

long numb,

LPDISPATCH part,

short first,

short section,

double attrTypeNumb);

Входные параметры:

nameLib | \- имя библиотеки стилей спецификации,  
---|---  
numb | \- номер стиля спецификации в библиотеке,  
part | \- указатель на интерфейс добавляемого компонента [ksPart](kspart.html),  
first | \- 1 - первый объект, 0 - следующий объект,  
section | \- номер раздела, в котором нужно найти объект (0 - номер не ограничивается),  
attrTypeNumb | \- номер типа атрибута, для которого нужно найти объект (0 - номер не ограничивается).  
  
Возвращаемое значение:

| \- указатель на объект спецификации.  
---|---  
  
Синтаксис COM:

[ISpecification3D::GetSpcObjForGeomWithLimit](ispecification3d_getspcobjforgeomwithlimit.html)

Подразделы:

(отсутствуют)
