# Интерфейс операции объединения компонентов (ksUnionComponentsDefinition и IUnionComponentsDefinition)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) |  Scroll [ [ [ ](ksunioncomponentsdefinition_methods.html "К следующему разделу")](nt_surface.html "На уровень выше")](ksmacro3ddefinition_setuserparam.html "К предыдущему разделу")  
---|---  
  
Интерфейс операции объединения компонентов.

ksUnionComponentsDefinition | \- интерфейс Automation  
---|---  
IUnionComponentsDefinition | \- интерфейс COM  
  
Примечания.

1\. Позволяет создать объединение двух или более деталей, входящих в сборку в новой или уже существующей детали.

2\. Операция доступна в режиме редактирования детали в контексте сборки.

3\. Для входа в режим редактирования детали в контексте сборки используется функция [ksPart::BeginEdit](kspart_beginedit.html).

4\. В операции объединения могут участвовать только детали. Объединить деталь с подсборкой невозможно.

5\. При необходимости вы можете скрыть или исключить из расчета детали, объединением которых является новая деталь.

6\. Данный интерфейс можно получить, используя метод интерфейса элемента модели [ksEntity::GetDefinition](ksentity_getdefinition.html) или [IEntity::GetDefinition](ksentity_getdefinition.html).

Подразделы:

[ksUnionComponentsDefinition - методы ](ksunioncomponentsdefinition_methods.html)
