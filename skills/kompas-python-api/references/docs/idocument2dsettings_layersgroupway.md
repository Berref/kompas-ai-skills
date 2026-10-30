# LayersGroupWay - Способ группировки слоев

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс IDocument2DSettings ](idocument2dsettings.html) > [IDocument2DSettings - свойства ](idocument2dsettings_props.html) |  Scroll [ [ [ ](idocument2dsettings_roughmodification.html "К следующему разделу")](idocument2dsettings_props.html "На уровень выше")](idocument3dsettings_embodimentsreportsettings.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocument2dsettings.html)

Тип данных: из перечисления [LayersGroupWayEnum](layersgroupwayenum.html)

Синтаксис Automation:

LayersGroupWay = iObject.LayersGroupWay | Получить свойство ([* ](1.html))  
---|---  
iObject.LayersGroupWay = LayersGroupWay | Установить свойство ([* ](1.html))  
LayersGroupWay = iObject.GetLayersGroupWay() | Получить свойство ([**](2.html))  
iObject.SetLayersGroupWay (LayersGroupWay) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_LayersGroupWay (&LayersGroupWay) | Получить свойство,  
---|---  
iObject->put_LayersGroupWay (LayersGroupWay) | Установить свойство.  
  
Примечание:

1\. Если данному свойству установлено значение wgLayers, то в документе будут создаваться и использоваться статические и динамические (фильтры) группы слоев.

2\. Если свойству установлено значение wgLayersCharacteristics, то в документе будут создаваться и использоваться группы свойств слоев.

3\. Изменение способа группировки в документе приводит к необратимым изменениям созданных групп и фильтров.

Подразделы:

(отсутствуют)
