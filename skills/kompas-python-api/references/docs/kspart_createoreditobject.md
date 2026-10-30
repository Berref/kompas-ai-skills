# CreateOrEditObject - Запустить процесс создания или редактирования объекта

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_curveintersection.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_colorparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

LPDISPATCH CreateOrEditObject (short objType, LPDISPATCH editObj);

Синтаксис COM:

LPENTITY CreateOrEditObject (short objType, LPENTITY editObj);

Входные параметры:

objType | \- тип создаваемого объекта, выбирается из [Obj3dType](obj3dtype.html),  
---|---  
editObj | \- редактируемый объект.  
  
[Типы компонентов...](part_type.html)

Возвращаемое значение:

| \- Указатель на интерфейс объекта [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Примечание:

1\. Для создания нового объекта необходимо передать методу тип objType и нулевой указатель editObj.

2\. Для редактирования уже существующего объекта необходимо передать методу указатель editObj на этот объект, переданный тип objType при этом игнорируется.

Подразделы:

(отсутствуют)
