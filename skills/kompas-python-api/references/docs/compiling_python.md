# Python

[Компиляция библиотек](compiling_libraries.html) |  Scroll [ [ [ ](vc_recommendations.html "К следующему разделу")](compiling_libraries.html "На уровень выше")](compiling_visual_c.html "К предыдущему разделу")  
---|---  
  
Для получения возможности использования API Компас в Python требуется выполнить импорт с tlb-файлов ksConstants.tlb, ksConstants3D.tlb, kAPI5.tlb, kAPI7.tlb:

from win32com.client import gencache  
kompas6_constants = gencache.EnsureModule("{75C9F5D0-B5B8-4526-8681-9903C567D2ED}", 0, 1, 0).constants  
kompas6_constants_3d = gencache.EnsureModule("{2CAF168C-7961-4B90-9DA2-701419BEEFE3}", 0, 1, 0).constants

kompas6_api5_module = gencache.EnsureModule("{0422828C-F174-495E-AC5D-D31014DBBE87}", 0, 1, 0)  
kompas_api7_module = gencache.EnsureModule("{69AC2981-37C0-4379-84FD-5DD2F3C0A520}", 0, 1, 0)
