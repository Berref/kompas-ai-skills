# geomArray - Признак использования геометрического копирования

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования ](int_copy.html) > [Копия элементов детали по кривой (Интерфейсы ksCurveCopyDefinition и ICopyCurveDefinition) ](kscurvecopydefinition.html) > [ksCurveCopyDefinition - свойства ](kscurvecopydefinition_props.html) |  Scroll [ [ [ ](kscurvecopydefinition_keepangle.html "К следующему разделу")](kscurvecopydefinition_props.html "На уровень выше")](kscurvecopydefinition_fullcurve.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurvecopydefinition.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- использовать геометрическое копирование. Содержимое операций источников (грани, ребра) копируется без пересчета. В простых случаях операция ускоряется, но возможны ошибки при копировании скруглений и фасок на криволинейных поверхностях;  
---|---  
FALSE | \- при копировании все операции-источники строятся заново, т.е. производится полноценный расчет.  
  
Синтаксис Automation:

geomArray = iCopyCurveDefinition.geomArray | Получить свойство([* ](1.html))  
---|---  
iCopyCurveDefinition.geomArray = geomArray | Установить свойство ([* ](1.html))  
geomArray = iCopyCurveDefinition.GetGeomArray() | Получить свойство ([**](2.html))  
iCopyCurveDefinition.SetGeomArray( geomArray) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
