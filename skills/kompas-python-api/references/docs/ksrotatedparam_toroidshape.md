# toroidShape - Признак тороида

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Параметры элемента вращения (Интерфейсы ksRotatedParam, IRotatedParam) ](ksrotatedparam.html) > [IRotatedParam - свойства ](ksrotatedparam_props.html) |  Scroll [ [ [ ](kscurve3d.html "К следующему разделу")](ksrotatedparam_props.html "На уровень выше")](ksrotatedparam_direction.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksrotatedparam.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- тороид,  
---|---  
FALSE | \- сфероид.  
  
Синтаксис Automation:

toroidShape = iRotatedParam.toroidShape | Получить свойство([* ](1.html))  
---|---  
iRotatedParam.toroidShape = toroidShape | Установить свойство ([* ](1.html))  
toroidShape = iRotatedParam.GetToroidShape() | Получить свойство ([**](2.html))  
iRotatedParam.SetToroidShape (toroidShape | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
