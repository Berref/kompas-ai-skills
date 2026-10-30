# keepAngle - Признак сохранения угла элементов относительно траектории в начальной точке

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования ](int_copy.html) > [Копия элементов детали по кривой (Интерфейсы ksCurveCopyDefinition и ICopyCurveDefinition) ](kscurvecopydefinition.html) > [ksCurveCopyDefinition - свойства ](kscurvecopydefinition_props.html) |  Scroll [ [ [ ](sence.html "К следующему разделу")](kscurvecopydefinition_props.html "На уровень выше")](kscurvecopydefinition_geomarray.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurvecopydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- сохранять угол,  
---|---  
FALSE | \- не сохранять угол.  
  
Синтаксис Automation:

keepAngle = iCopyCurve.keepAngle | Получить свойство([* ](1.html))  
---|---  
iCopyCurve.keepAngle = keepAngle | Установить свойство ([* ](1.html))  
keepAngle = iCopyCurve.GetKeepAngle() | Получить свойство ([**](2.html))  
iCopyCurve.SetKeepAngle(keepAngle) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
