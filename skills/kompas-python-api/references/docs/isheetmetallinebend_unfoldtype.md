# UnfoldType - Способ определения длины развертки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalLineBend ](isheetmetallinebend.html) > [ISheetMetalLineBend - свойства ](isheetmetallinebend_props.html) |  Scroll [ [ [ ](isheetmetalribs.html "К следующему разделу")](isheetmetallinebend_props.html "На уровень выше")](isheetmetallinebend_straighten.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetallinebend.html)

Тип данных: из перечисления [ksUnfoldTypeEnum](ksunfoldtypeenum.html)

Синтаксис Automation:

UnfoldType = iObject.UnfoldType; | Получить свойство ([* ](1.html))  
---|---  
iObject.UnfoldType = UnfoldType; | Установить свойство ([* ](1.html))  
UnfoldType = iObject.GetUnfoldType; | Получить свойство ([**](2.html))  
iObject.SetUnfoldType( UnfoldType ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_UnfoldType( &UnfoldType ); | Получить свойство  
---|---  
iObject->put_UnfoldType( UnfoldType ); | Установить свойство  
  
Примечание.

Позволяет считывать и устанавливать способ определения длины развертки. Если задан способ определения длины развертки - из таблицы, то будут недоступны свойства установки (Set) для коэффициента нейтрального слоя, величины сгиба и уменьшения сгиба, т.к они будут браться из таблицы.

Подразделы:

(отсутствуют)
