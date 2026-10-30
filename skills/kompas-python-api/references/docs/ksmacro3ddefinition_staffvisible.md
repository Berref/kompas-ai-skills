# StaffVisible - Управление видимостью состава

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Интерфейс макроэлемента (ksMacro3DDefinition, IMacro3DDefinition) ](ksmacro3ddefinition.html) > [IMacro3DDefinition - свойства ](ksmacro3ddefinition_props.html) |  Scroll [ [ [ ](ksmacro3ddefinition_methods.html "К следующему разделу")](ksmacro3ddefinition_props.html "На уровень выше")](ksmacro3ddefinition_propertyobjecteditable.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmacro3ddefinition.html)

Тип данных: BOOL

Синтаксис Automation:

staffVisible = iObject.StaffVisible | Получить свойство ([* ](1.html))  
---|---  
iObject.StaffVisible = staffVisible | Установить свойство([* ](1.html))  
staffVisible = iObject.GetStaffVisible() | Получить свойство ([**](2.html))  
iObject.SetStaffVisible (staffVisible) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

staffVisible = iObject->GetStaffVisible() | Получить свойство  
---|---  
iObject->SetStaffVisible (&StaffVisible) | Установить свойство  
  
Значение свойства:

TRUE | \- состав объекта можно посмотреть в Дереве построения,  
---|---  
FALSE | \- состав недоступен для просмотра.  
  
Примечание:

Свойство позволяет управлять видимостью состава макроэлемента.

Подразделы:

(отсутствуют)
