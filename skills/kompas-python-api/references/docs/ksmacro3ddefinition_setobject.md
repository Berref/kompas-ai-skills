# SetObject - Сохранить указатель на объект в макро по индексу

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Интерфейс макроэлемента (ksMacro3DDefinition, IMacro3DDefinition) ](ksmacro3ddefinition.html) > [IMacro3DDefinition - методы ](ksmacro3ddefinition_methods.html) |  Scroll [ [ [ ](ksmacro3ddefinition_setuserparam.html "К следующему разделу")](ksmacro3ddefinition_methods.html "На уровень выше")](ksmacro3ddefinition_getuserparamsize.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmacro3ddefinition.html)

Синтаксис Automation:

BOOL SetObject(long index, LPDISPATCH obj);

Синтаксис COM:

BOOL SetObject(long index, LPUNKNOWN obj);

Входные параметры:

index | \- номер объекта,  
---|---  
obj | \- указатель на интерфейс объекта.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

Объект - это вспомогательная информация, и визуально никак не отображается. Например, если создать болт как макро относительно какого-нибудь объекта (например отверстие - цилиндрическая поверхность), и запомнить это отверстие в макро болта, то при следующем редактирование можно получить сохранённый указатель на отверстие.

См. также: [IMacro3DDefinition::GetObject](ksmacro3ddefinition_getobject.html)

Подразделы:

(отсутствуют)
