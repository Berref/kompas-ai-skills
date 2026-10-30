# GetObject - Получить указатель на вспомогательный объект, сохраненный в макро по индексу

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Интерфейс макроэлемента (ksMacro3DDefinition, IMacro3DDefinition) ](ksmacro3ddefinition.html) > [IMacro3DDefinition - методы ](ksmacro3ddefinition_methods.html) |  Scroll [ [ [ ](ksmacro3ddefinition_getuserlibrarycommand.html "К следующему разделу")](ksmacro3ddefinition_methods.html "На уровень выше")](ksmacro3ddefinition_getcountobj.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmacro3ddefinition.html)

Синтаксис Automation:

LPDISPATCH GetObject (long index);

Синтаксис COM:

LPUNKNOWN GetObject (long index);

Входные параметры:

index | \- номер объекта.  
---|---  
  
Возвращаемое значение:

| \- Указатель на интерфейс IDispatch или IUnknown сохранённого объекта.  
---|---  
  
Примечания:

Объект - это вспомогательная информация, и визуально никак не отображается. Например, если создать болт как макро относительно какого-нибудь объекта (например отверстие - цилиндрическая поверхность), и запомнить это отверстие в макро болта, то при следующем редактирование можно получить сохранённый указатель на отверстие.

См. также: [IMacro3DDefinition::SetObject](ksmacro3ddefinition_setobject.html)

Подразделы:

(отсутствуют)
