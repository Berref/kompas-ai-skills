# Number - Номер слоя для фильтрации

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс ILayerFilterCondition ](ilayerfiltercondition.html) > [ILayerFilterCondition - свойства ](ilayerfiltercondition_props.html) |  Scroll [ [ [ ](ilayerfiltercondition_projected.html "К следующему разделу")](ilayerfiltercondition_props.html "На уровень выше")](ilayerfiltercondition_name.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayerfiltercondition.html)

Тип данных: BSTR (строка)

Синтаксис Automation:

Number = iObject.Number | Получить свойство ([* ](1.html))  
---|---  
iObject.Number = Number | Установить свойство ([* ](1.html))  
Number = iObject.GetNumber() | Получить свойство ([**](2.html))  
iObject.SetNumber (Number) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Number (&Number) | Получить свойство  
---|---  
iObject->put_Number (Number) | Установить свойство  
  
Примечание:

1\. При задании условия фильтрации по номеру можно использовать маски. В масках знак «*» заменяет любое количество любых символов. Знак «?» заменяет один любой символ.

2\. После установки нового значения данного свойства состав группы будет автоматически изменен.

Подразделы:

(отсутствуют)
