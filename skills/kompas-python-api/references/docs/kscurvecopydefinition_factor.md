# factor - Признак полного шага

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования ](int_copy.html) > [Копия элементов детали по кривой (Интерфейсы ksCurveCopyDefinition и ICopyCurveDefinition) ](kscurvecopydefinition.html) > [ksCurveCopyDefinition - свойства ](kscurvecopydefinition_props.html) |  Scroll [ [ [ ](kscurvecopydefinition_fullcurve.html "К следующему разделу")](kscurvecopydefinition_props.html "На уровень выше")](kscurvecopydefinition_count.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurvecopydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- полный шаг,  
---|---  
FALSE | \- шаг между соседними копиями.  
  
Синтаксис Automation:

factor = iCopyCurve.factor | Получить свойство([* ](1.html))  
---|---  
iCopyCurve.factor = factor | Установить свойство ([* ](1.html))  
factor = iCopyCurve.GetFactor() | Получить свойство ([**](2.html))  
iCopyCurve.SetFactor(factor) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
