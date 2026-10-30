# fullCurve - Признак распределения копий

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования ](int_copy.html) > [Копия элементов детали по кривой (Интерфейсы ksCurveCopyDefinition и ICopyCurveDefinition) ](kscurvecopydefinition.html) > [ksCurveCopyDefinition - свойства ](kscurvecopydefinition_props.html) |  Scroll [ [ [ ](kscurvecopydefinition_geomarray.html "К следующему разделу")](kscurvecopydefinition_props.html "На уровень выше")](kscurvecopydefinition_factor.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurvecopydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- по всей длине траектории,  
---|---  
FALSE | \- по шагу и количеству.  
  
Синтаксис Automation:

fullCurve = iCopyCurve.fullCurve | Получить свойство([* ](1.html))  
---|---  
iCopyCurve.fullCurve = fullCurve | Установить свойство ([* ](1.html))  
fullCurve = iCopyCurve.GetFullCurve() | Получить свойство ([**](2.html))  
iCopyCurve.SetFullCurve(fullCurve) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
