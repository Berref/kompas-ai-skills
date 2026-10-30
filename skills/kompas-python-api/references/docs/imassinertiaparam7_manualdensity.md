# ManualDensity - Ручное задание плотности

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IMassInertiaParam7 ](imassinertiaparam7.html) > [IMassInertiaParam7 - свойства ](imassinertiaparam7_props.html) |  Scroll [ [ [ ](imassinertiaparam7_manualmass.html "К следующему разделу")](imassinertiaparam7_props.html "На уровень выше")](imassinertiaparam7_lyz.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imassinertiaparam7.html)

Тип данных: double

Синтаксис Automation:

iObject.ManualDensity = ManualDensity | Установить свойство ([* ](1.html))  
---|---  
iObject.SetManualDensity( ManualDensity) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->put_ManualDensity( ManualDensity ) | Устанoовить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для записи. Позволяет явно установить значение плотности. Введенное значение появится в поле Плотность.

2\. Единицы измерения плотности определяются значениями свойств [IMassInertiaParam7::MassUnits](imassinertiaparam7_massunits.html) и [IMassInertiaParam7::LengthUnits](imassinertiaparam7_lengthunits.html).

3\. Для задания плотности необходимо выполнить следующие действия:

•установить режим Расчет параметров плотности (см. свойство [IMassInertiaParam7::MassSettingMode](imassinertiaparam7_masssettingmode.html)).

•установить режим Ручной ввод плотности (см. свойство [IMassInertiaParam7::DensityMode](imassinertiaparam7_densitymode.html)).

Подразделы:

(отсутствуют)
