# factor - Признак полного шага

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования компонентов сборки ](nt_copy_asm.html) > [Копия компонентов сборки по кривой (Интерфейсы ksCurvePartArrayDefinition, ICurvePartArrayDefinition) ](kscurvepartarraydefinition.html) > [ksCurvePartArrayDefinition - свойства ](kscurvepartarraydefinition_props.html) |  Scroll [ [ [ ](kscurvepartarraydefinition_fullcurve.html "К следующему разделу")](kscurvepartarraydefinition_props.html "На уровень выше")](kscurvepartarraydefinition_count.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurvepartarraydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- свойство [step](kscurvepartarraydefinition_step.html) устанавливает расстояние между крайними элементами массива вдоль траектории,  
---|---  
FALSE | \- свойство [step](kscurvepartarraydefinition_step.html) устанавливает расстояние между соседними элементами массива вдоль траектории.  
  
Синтаксис Automation:

factor = iArrayCurve.factor | Получить свойство([* ](1.html))  
---|---  
iArrayCurve.factor = factor | Установить свойство ([* ](1.html))  
factor = iArrayCurve.GetFactor() | Получить свойство ([**](2.html))  
iArrayCurve.SetFactor(factor) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
