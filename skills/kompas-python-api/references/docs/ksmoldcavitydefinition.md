# Интерфейс операции вычитания компонентов (ksMoldCavityDefinition, IMoldCavityDefinition)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) |  Scroll [ [ [ ](ksmoldcavitydefinition_props.html "К следующему разделу")](nt_surface.html "На уровень выше")](ksloftsurfacedefinition_sketches.html "К предыдущему разделу")  
---|---  
  
Интерфейс операции вычитания компонентов.

ksMoldCavityDefinition | \- интерфейс Automation  
---|---  
IMoldCavityDefinition | \- интерфейс COM  
  
Примечания.

1\. Позволяет создать полость, имеющую форму другой детали.

2\. Операция доступна в режиме редактирования детали в контексте сборки.

3\. Для входа в режим редактирования детали в контексте сборки используется функция [ksPart::BeginEdit](kspart_beginedit.html).

4\. В операции вычитания могут участвовать только детали. Вычесть из детали подсборку невозможно.

5\. Если необходимо, чтобы размеры создаваемой полости отличались от размеров вычитаемой детали, нужно задать коэффициент масштабирования в процентах [scale](ksmoldcavitydefinition_scale.html).

6\. Данный интерфейс можно получить, используя метод интерфейса элемента модели [ksEntity::GetDefinition](ksentity_getdefinition.html) или [IEntity::GetDefinition](ksentity_getdefinition.html).

Подразделы:

[ksMoldCavityDefinition - свойства ](ksmoldcavitydefinition_props.html)

[ksMoldCavityDefinition - методы ](ksmoldcavitydefinition_methods.html)
