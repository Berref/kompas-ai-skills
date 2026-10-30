# sketchShiftType - Тип движения сечения по траектории

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Приклеенный кинематический элемент (Интерфейсы ksBossEvolutionDefinition, IBossEvolutionDefinition) ](ksbossevolutiondefinition.html) > [IBossEvolutionDefinition - свойства ](ksbossevolutiondefinition_props.html) |  Scroll [ [ [ ](ksbossevolutiondefinition_methods.html "К следующему разделу")](ksbossevolutiondefinition_props.html "На уровень выше")](ksbossevolutiondefinition_choosetype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbossevolutiondefinition.html)

Тип данных: short

Значения свойства:

0 | \- образующая переносится параллельно самой себе,  
---|---  
1 | \- образующая при переносе сохраняет исходный угол с направляющей,  
2 | \- плоскость образующей выставляется и сохраняется ортогональной направляющей.  
  
Синтаксис Automation:

sketchShiftType = iEvolution.sketchShiftType | Получить свойство([* ](1.html))  
---|---  
iEvolution.sketchShiftType = sketchShiftType | Установить свойство ([* ](1.html))  
sketchShiftType = iEvolution.GetSketchShiftType() | Получить свойство ([**](2.html))  
iEvolution.SetSketchShiftType(sketchShiftType) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
