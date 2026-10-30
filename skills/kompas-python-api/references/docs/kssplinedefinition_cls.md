# cls - Признак замкнутости сплайна

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы пространственных кривых ](int_pr_curve.html) > [Сплайн (Интерфейсы ksSplineDefinition и ISplineDefinition) ](kssplinedefinition.html) > [ISplineDefinition - свойства ](kssplinedefinition_props.html) |  Scroll [ [ [ ](kssplinedefinition_degree.html "К следующему разделу")](kssplinedefinition_props.html "На уровень выше")](kssplinedefinition_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssplinedefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- замкнутый сплайн,  
---|---  
FALSE | \- разомкнутый сплайн.  
  
Синтаксис Automation:

cls = iSpline.cls | Получить свойство ([* ](1.html))  
---|---  
iSpline.cls = cls | Установить свойство ([* ](1.html))  
cls = iSpline.GetClosed() | Получить свойство ([**](2.html))  
iSpline.SetClosed(cls) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
