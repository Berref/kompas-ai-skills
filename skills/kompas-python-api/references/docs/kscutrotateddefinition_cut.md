# cut - Признак результата операции

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Вырезанный элемент вращения(ИнтерфейсыksCutRotatedDefinition, ICutRotatedDefinition) ](kscutrotateddefinition.html) > [ICutRotatedDefinition - свойства ](kscutrotateddefinition_props.html) |  Scroll [ [ [ ](kscutrotateddefinition_directiontype.html "К следующему разделу")](kscutrotateddefinition_props.html "На уровень выше")](kscutrotateddefinition_choosetype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutrotateddefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- результат операции - вычитание объекта,  
---|---  
FALSE | \- результат операции - пересечение объектов.  
  
Синтаксис Automation:

cut = iCutRotated.cut | Получить свойство([* ](1.html))  
---|---  
iCutRotated.cut = cut | Установить свойство ([* ](1.html))  
cut = iCutRotated.GetCut() | Получить свойство ([**](2.html))  
iCutRotated.SetCut (cut) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
