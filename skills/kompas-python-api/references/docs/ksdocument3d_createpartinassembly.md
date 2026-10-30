# CreatePartInAssembly - Получить указатель на интерфейс детали, создаваемой в сборке

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_defaultplacement.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_create.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

LPDISPATCH CreatePartInAssembly (BSTR fileName,

LPDISPATCH plane);

Синтаксис COM:

LPPART CreatePartInAssembly (LPOLESTR fileName,

LPENTITY plane);

Входные параметры:

fileName | \- имя файла детали создаваемой в сборке,  
---|---  
plane | \- указатель на интерфейс плоского объекта [ksEntity](ksentity.html) или [IEntity](ksentity.html), к которому приклеивается деталь.  
  
Возвращаемое значение:

| \- указатель на интерфейс детали, создаваемой в сборке [ksPart](kspart.html) или [IPart](kspart.html).  
---|---  
  
Подразделы:

(отсутствуют)
