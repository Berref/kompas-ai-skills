# CompositionInherit - Наследовать состав родительского объекта

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс IDocument2DSettings ](idocument2dsettings.html) > [IDocument2DSettings - свойства ](idocument2dsettings_props.html) |  Scroll [ [ [ ](idocument2dsettings_decimaldelimitertype.html "К следующему разделу")](idocument2dsettings_props.html "На уровень выше")](idocument2dsettings_autosortobjectsparameters.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocument2dsettings.html)

Тип данных: BOOL

Синтаксис Automation:

CompositionInherit = iObject.CompositionInherit | Получить свойство ([* ](1.html))  
---|---  
iObject.CompositionInherit = CompositionInherit | Установить свойство ([* ](1.html))  
CompositionInherit = iObject.GetCompositionInherit() | Получить свойство ([**](2.html))  
iObject.SetCompositionInherit (CompositionInherit) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_CompositionInherit (&CompositionInherit) | Получить свойство,  
---|---  
iObject->put_CompositionInherit (CompositionInherit) | Установить свойство.  
  
Примечание:

1\. Данное свойство используется, если свойству [LayersGroupWay](idocument2dsettings_layersgroupway.html) установлено значение wgLayersCharacteristics.

2\. Если установлено значение TRUE, то при создании группы свойств слоев будет выполнено следующее:

•если родительским элементом является группа свойств, то в новую группу будут скопированы все слои родительской группы и назначаемые им в данной группе свойства,

•если родительским элементом является вид, то новая группа будет содержать все слои вида и их свойства,

•если родительским элементом является корневой элемент Документ, то новая группа будет содержать все слои всех видов.

3\. Изменение способа группировки в документе приводит к необратимым изменениям созданных групп.

Подразделы:

(отсутствуют)
