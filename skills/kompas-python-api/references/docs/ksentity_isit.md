# IsIt - Проверить объект на соответствие указанному типу

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [ksEntity - методы ](ksentity_methods.html) |  Scroll [ [ [ ](ksentity_setadvancedcolor.html "К следующему разделу")](ksentity_methods.html "На уровень выше")](ksentity_iscreated.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksentity.html)

Синтаксис Automation:

BOOL IsIt (short objType);

Синтаксис COM:

BOOL IsIt (short objType)

Входной параметр:

objType | \- тип объекта.  
---|---  
  
Возвращаемое значение:

TRUE | \- если тип объекта указан правильно.  
---|---  
  
[Типы объектов...](obj3dtype.html)

Примечание:

Числовой идентификатор типа объекта не должен превышать идентификатора объекта, всегда последнего из Entity.

Подразделы:

(отсутствуют)
