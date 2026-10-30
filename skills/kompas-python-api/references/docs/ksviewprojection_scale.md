# scale - Масштаб отображения модели в окне

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс коллекции проекций отображения модели (Интерфейсы ksViewProjectionCollection, IViewProjectionCollection) ](ksviewprojectioncollection.html) > [Проекции отображения модели в окне (Интерфейсы ksViewProjection, IViewProjection) ](ksviewprojection.html) > [IViewProjection - свойства ](ksviewprojection_props.html) |  Scroll [ [ [ ](ksviewprojection_methods.html "К следующему разделу")](ksviewprojection_props.html "На уровень выше")](ksviewprojection_name.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksviewprojection.html)

Тип данных: double

Синтаксис Automation:

scale = iViewProjection.scale | Получить свойство([* ](1.html))  
---|---  
iViewProjection.scale = scale | Установить свойство ([* ](1.html))  
scale = iViewProjection.GetScale() | Получить свойство ([**](2.html))  
iViewProjection.SetScale(scale) | Установить свойство ([**](2.html))  
  
Примечание:

Масштаб можно установить для любой проекции. Если значение масштаба равно -1, то масштаб отображения будет задан таким образом, чтобы в окне был показан документ целиком.

Если проекция является текущей, SetScale устанавливает нужный масштаб сразу.

Получить масштаб отображения можно для пользовательской проекции, либо для текущей.

Подразделы:

(отсутствуют)
