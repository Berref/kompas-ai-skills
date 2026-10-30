# Name - Имя слоя для фильтрации

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс ILayerFilterCondition ](ilayerfiltercondition.html) > [ILayerFilterCondition - свойства ](ilayerfiltercondition_props.html) |  Scroll [ [ [ ](ilayerfiltercondition_number.html "К следующему разделу")](ilayerfiltercondition_props.html "На уровень выше")](ilayerfiltercondition_haveobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayerfiltercondition.html)

Тип данных: BSTR (строка)

Синтаксис Automation:

Name = iObject.Name | Получить свойство ([* ](1.html))  
---|---  
iObject.Name = Name | Установить свойство ([* ](1.html))  
Name = iObject.GetName() | Получить свойство ([**](2.html))  
iObject.SetName (Name) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Name (&Name) | Получить свойство  
---|---  
iObject->put_Name (Name) | Установить свойство  
  
Примечание:

1\. При задании условия фильтрации по номеру можно использовать маски. В масках знак «*» заменяет любое количество любых символов. Знак «?» заменяет один любой символ.

2\. После установки нового значения данного свойства состав группы будет автоматически изменен.

Подразделы:

(отсутствуют)
