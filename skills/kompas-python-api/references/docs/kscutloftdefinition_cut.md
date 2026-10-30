# cut - Признак результата операции

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Вырезанный элемент по сечениям (Интерфейсы ksCutLoftDefinition, ICutLoftDefinition) ](kscutloftdefinition.html) > [ICutLoftDefinition - свойства ](kscutloftdefinition_props.html) |  Scroll [ [ [ ](kscutloftdefinition_methods.html "К следующему разделу")](kscutloftdefinition_props.html "На уровень выше")](kscutloftdefinition_choosetype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutloftdefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- результат операции - вычитание элемента,  
---|---  
FALSE | \- результат операции - пересечение элементов.  
  
Синтаксис Automation:

cut = iCutLoft.cut | Получить свойство([* ](1.html))  
---|---  
iCutLoft.cut = cut | Установить свойство ([* ](1.html))  
cut = iCutLoft.GetCut() | Получить свойство ([**](2.html))  
iCutLoft.SetCut (cut) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
