# NewEntity - Создать новый интерфейс объекта и получить указатель на него

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_putstorage.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_isdetail.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

LPDISPATCH NewEntity (short objType);

Синтаксис COM:

LPENTITY NewEntity (short objType);

Входной параметр:

objType | \- [тип объекта](obj3dtype.html).  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Примечание:

Реальный объект создается в модели после вызова метода [Create](ksentity_create.html).

Подразделы:

(отсутствуют)
