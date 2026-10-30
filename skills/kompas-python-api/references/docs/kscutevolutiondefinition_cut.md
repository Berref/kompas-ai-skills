# cut - Признак результата операции

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Вырезанный кинематический элемент (Интерфейс ksCutEvolutionDefinition, ICutEvolutionDefinition) ](kscutevolutiondefinition.html) > [ICutEvolutionDefinition - свойства ](kscutevolutiondefinition_props.html) |  Scroll [ [ [ ](kscutevolutiondefinition_sketchshifttype.html "К следующему разделу")](kscutevolutiondefinition_props.html "На уровень выше")](kscutevolutiondefinition_choosetype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutevolutiondefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- результат операции - вычитание элемента,  
---|---  
FALSE | \- результат операции - пересечение элементов.  
  
Синтаксис Automation:

cut = iEvolution.cut | Получить свойство([* ](1.html))  
---|---  
iEvolution.cut = cut | Установить свойство ([* ](1.html))  
cut = iEvolution.GetCut() | Получить свойство ([**](2.html))  
iEvolution.SetCut(cut) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
