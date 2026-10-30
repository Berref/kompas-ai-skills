# tangent - Признак продолжения скругления по касательным ребрам

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Скругление (Интерфейсы ksFilletDefinition, IFilletDefinition) ](ksfilletdefinition.html) > [IFilletDefinition - свойства ](ksfilletdefinition_props.html) |  Scroll [ [ [ ](ksfilletdefinition_methods.html "К следующему разделу")](ksfilletdefinition_props.html "На уровень выше")](ksfilletdefinition_radius.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfilletdefinition.html)

Тип данных: BOOL

Синтаксис Automation:

tangent = iFilletDefinition.tangent | Получить свойство([* ](1.html))  
---|---  
iFilletDefinition.tangent = tangent | Установить свойство ([* ](1.html))  
tangent = iFilletDefinition.GetTangent() | Получить свойство ([**](2.html))  
iFilletDefinition.SetTangent (tangent) | Установить свойство ([**](2.html))  
  
Значения свойства:

TRUE | \- продолжать скругление по касательным ребрам,  
---|---  
FALSE | \- не продолжать скругление по касательным ребрам.  
  
Подразделы:

(отсутствуют)
