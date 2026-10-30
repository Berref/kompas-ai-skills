# ps - Признак ориентации размерной линии

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров размеров ](cf1713887.html) > [Линейные размеры ](cf1760627.html) > [Привязка размера (Интерфейс ksLDimSourceParam) ](ksldimsourceparam.html) > [ksLDimSourceParam - свойства ](ksldimsourceparam_props.html) |  Scroll [ [ [ ](ksldimsourceparam_x1.html "К следующему разделу")](ksldimsourceparam_props.html "На уровень выше")](ksldimsourceparam_dx.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksldimsourceparam.html)

Тип данных:short.

Значения свойства:

0 | \- горизонтально,  
---|---  
1 | \- вертикально,  
2 | \- параллельно отрезку,  
3 | \- по [dx, dy](ksldimsourceparam_dx.html),  
4 | \- параллельно отрезку с выносными линиями по dx, dy.  
  
Синтаксис Automation:

ps = iLDimSource.ps | Получить свойство ([* ](1.html))  
---|---  
iLDimSource.ps = ps | Установить свойство ([* ](1.html))  
ps = iLDimSource.GetPs() | Получить свойство ([**](2.html))  
iLDimSource.SetPs( ps ) | Установить свойство ([**](2.html))  
  
Подразделы:

(отсутствуют)
