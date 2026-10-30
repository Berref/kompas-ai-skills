# fullCurve - Признак расположения копий вдоль всей траектории

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования компонентов сборки ](nt_copy_asm.html) > [Копия компонентов сборки по кривой (Интерфейсы ksCurvePartArrayDefinition, ICurvePartArrayDefinition) ](kscurvepartarraydefinition.html) > [ksCurvePartArrayDefinition - свойства ](kscurvepartarraydefinition_props.html) |  Scroll [ [ [ ](kscurvepartarraydefinition_keepangle.html "К следующему разделу")](kscurvepartarraydefinition_props.html "На уровень выше")](kscurvepartarraydefinition_factor.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurvepartarraydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- первый и последний элементы массива располагаются соответственно в начальной и конечной точках траектории. Свойства [step](kscurvepartarraydefinition_step.html) и [factor](kscurvepartarraydefinition_factor.html) определяются автоматически с учетом условия [count](kscurvepartarraydefinition_count.html).  
---|---  
FALSE | \- элементы массива располагаются вдоль траектории в соответствии со свойствами step, factor и count.  
  
Синтаксис Automation:

fullCurve = iArrayCurve.fullCurve | Получить свойство([* ](1.html))  
---|---  
iArrayCurve.fullCurve = fullCurve | Установить свойство ([* ](1.html))  
fullCurve = iArrayCurve.GetFullCurve() | Получить свойство ([**](2.html))  
iArrayCurve.SetFullCurve(fullCurve) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
