# leaderLength - Длина ответвлений

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Знак изменения (Интерфейс ksChangeLeaderParam) ](kschangeleaderparam.html) > [ksChangeLeaderParam - свойства ](kschangeleaderparam_props.html) |  Scroll [ [ [ ](kschangeleaderparam_signheight.html "К следующему разделу")](kschangeleaderparam_props.html "На уровень выше")](kschangeleaderparam_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kschangeleaderparam.html)

Тип данных: double

Синтаксис Automation:

leaderLength = ksChangeLeaderParam.leaderLength | Получить свойство ([* ](1.html))  
---|---  
ksChangeLeaderParam.leaderLength = leaderLength | Установить свойство ([* ](1.html))  
leaderLength = ksChangeLeaderParam.GetleaderLength() | Получить свойство ([**](2.html))  
ksChangeLeaderParam.SetleaderLength( dirX ) | Установить свойство ([**](2.html))  
  
Примечание:

Если leaderLength >= 0, длина всех ответвлений одинакова и равна leaderLength.

Если leaderLength < 0 - ответвление на всю длину. Длина для каждого ответвления задается координатами конца ответвления.

Подразделы:

(отсутствуют)
