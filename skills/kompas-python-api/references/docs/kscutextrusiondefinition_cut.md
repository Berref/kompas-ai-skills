# cut - Признак результата операции

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Вырезанный элемент выдавливания (Интерфейсы ksCutExtrusionDefinition, ICutExtrusionDefinition) ](kscutextrusiondefinition.html) > [ICutExtrusionDefinition - свойства ](kscutextrusiondefinition_props.html) |  Scroll [ [ [ ](kscutextrusiondefinition_directiontype.html "К следующему разделу")](kscutextrusiondefinition_props.html "На уровень выше")](kscutextrusiondefinition_choosetype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscutextrusiondefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- результат операции - вычитание элемента,  
---|---  
FALSE | \- результат операции - пересечение элементов.  
  
Синтаксис Automation:

cut = iCutExtrusion.cut | Получить свойство([* ](1.html))  
---|---  
iCutExtrusion.cut = cut | Установить свойство ([* ](1.html))  
cut = iCutExtrusion.GetCut() | Получить свойство ([**](2.html))  
iCutExtrusion.SetCut(cut) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
