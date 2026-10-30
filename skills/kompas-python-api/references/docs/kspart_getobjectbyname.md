# GetObjectByName - Получить компонент по имени

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_getobject3dnotify.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_getobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

LPDISPATCH GetObjectByName( BSTR name,

short objType,

BOOL testFullName,

BOOL testIgnoreCase );

Синтаксис COM:

LPUNKNOWN GetObjectByName( LPOLESTR name,

short objType,

BOOL testFullName,

BOOL testIgnoreCase );

Входные параметры:

name | \- имя компонента,  
---|---  
objType | \- тип компонента,  
testFullName | \- полное имя компонента: TRUE - использовать полное имя, FALSE - частичное совпадение,  
testIgnoreCase | \- игнорировать регистр.  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Примечания:

Объект - это вспомогательная информация, и визуально никак не отображается. Например, если создать болт как макро относительно какого-нибудь объекта (например отверстие - цилиндрическая поверхность), и запомнить это отверстие в макро болта, то при следующем редактирование можно получить сохранённый указатель на отверстие.

См. также: [IPart::SetObject](kspart_setobject.html)

Подразделы:

(отсутствуют)
