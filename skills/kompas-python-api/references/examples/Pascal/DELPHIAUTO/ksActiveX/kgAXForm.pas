unit kgAXForm;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ExtCtrls, OleCtrls, KGAXLib_TLB, ksTlb, LDefin2d, LDefin3d;

type
  TForm1 = class(TForm)
    Panel1: TPanel;
    Button1: TButton;
    Button2: TButton;
    RadioGroup1: TRadioGroup;
    KGAX1: TKGAX;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure RadioGroup1Click(Sender: TObject);
    procedure FormDestroy(Sender: TObject);

  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.DFM}

procedure TForm1.Button1Click(Sender: TObject);
  var
    iKompas              : KompasObject;
    iDoc                 : ksDocument3D;
    iPart                : ksPart;
    iSketchEntity        : ksEntity;
    iSketchDef           : ksSketchDefinition;
    iPlaneEntity         : ksEntity;
    iSketchDocument2D    : ksDocument2D;
    iBaseExtrusionEntity : ksEntity;
    iBaseExtrusionDef    : ksBossExtrusionDefinition;
    iSketch2Entity       : ksEntity;
    iSketch2Def          : ksSketchDefinition;
    iSketch2Document2D   : ksDocument2D;
    iBossExtrusion       : ksEntity;
    iBossExtrusionDef    : ksBossExtrusionDefinition;
    iExtrusionProperty   : ksExtrusionParam;
    iThinProperty        : ksThinParam;
begin
  iKompas := KGAX1.GetKompasObject;
	iDoc    := ksDocument3D( iKompas.ActiveDocument3D );
//  iKompas.ksMessage( 'базовая операция выдавливания' );

 iPart := ksPart(iDoc.GetPart( pTop_Part )); // новый компонент

  if iPart <> nil then
  begin

    iSketchEntity := ksEntity( iPart.NewEntity( o3d_sketch ));

    if iSketchEntity <> nil then
    begin
      // интерфейс свойств эскиза
      iSketchDef := ksSketchDefinition(iSketchEntity.GetDefinition);

      if iSketchDef <> nil then
      begin
        // интерфейс плоскости XOY
        iPlaneEntity := ksEntity(iPart.GetDefaultEntity( o3d_planeXOY ));

        if iPlaneEntity <> nil then
        begin
          iSketchDef.SetPlane( iPlaneEntity ); // установим плоскость XOY базовой для эскиза
  	      iSketchDef.Angle := 45; // угол поворота эскиза
          iSketchEntity.Create; // создадим эскиз
          // интерфейс редактора эскиза
          iSketchDocument2D := ksDocument2D(iSketchDef.BeginEdit);

          if iSketchDocument2D <> nil then
          begin
            // введем новый эскиз - квадрат
            iSketchDocument2D.ksLineSeg(  50,  50, -50,  50, 1 );
	          iSketchDocument2D.ksLineSeg(  50, -50, -50, -50, 1 );
            iSketchDocument2D.ksLineSeg(  50, -50,  50,  50, 1 );
	          iSketchDocument2D.ksLineSeg( -50, -50, -50,  50, 1 );
	          iSketchDef.EndEdit; // завершение редактирования эскиза

	          iBaseExtrusionEntity := ksEntity(iPart.NewEntity( o3d_bossExtrusion ));

            if iBaseExtrusionEntity <> nil then
            begin
              // интерфейс свойств базовой операции выдавливания
              iBaseExtrusionDef := ksBossExtrusionDefinition(iBaseExtrusionEntity.GetDefinition);

              if iBaseExtrusionDef <> nil then
              begin
            		iBaseExtrusionDef.DirectionType := dtNormal; // направление выдавливания
            		iBaseExtrusionDef.SetSideParam( true,        //прямое направление
                                                etBlind ,    // строго на глубину
                                                200, 0, false );
	              iBaseExtrusionDef.SetThinParam( true, dtBoth, 10, 10 ); // тонкая стенка в два направления
		            iBaseExtrusionDef.SetSketch( iSketchEntity ); // эскиз операции выдавливания
		            iBaseExtrusionEntity.Create; // создать операцию

//                iKompas.ksMessage( 'изменим параметры операции выдавливания' );

                iBaseExtrusionDef.SetSideParam( false, //обратное направление
                                                etBlind, //строго на глубину
                                                150, 0, false );
		            iBaseExtrusionDef.DirectionType := dtBoth; // направление выдавливания ( в оба направления )
		            iBaseExtrusionEntity.Update; // обновить параметры


//                iKompas.ksMessage( 'приклеить элемент выдавливания' );

              	// создадим новый эскиз
		            iSketch2Entity := ksEntity(iPart.NewEntity( o3d_sketch ));

                if iSketch2Entity <> nil then
                begin
                  // интерфейс свойств эскиза
                  iSketch2Def := ksSketchDefinition(iSketch2Entity.GetDefinition);

                  if iSketch2Def <> nil then
                  begin
                    iSketch2Def.SetPlane( iPlaneEntity ); // установим плоскость
            		    iSketch2Def.Angle := 45; // повернем эскиз на 45 град.
		                iSketch2Entity.Create; // создадим эскиз

                    // интерфейс редактора эскиза
		                iSketch2Document2D := ksDocument2D(iSketch2Def.BeginEdit);
		                iSketch2Document2D.ksCircle( 0, 0, 150, 1 );
		                iSketch2Def.EndEdit; // завершение редактирования эскиза

                    // приклеим выдавливанием
		                iBossExtrusion := ksEntity(iPart.NewEntity( o3d_bossExtrusion ));

                    if iBossExtrusion <> nil then
                    begin
                      iBossExtrusionDef := ksBossExtrusionDefinition(iBossExtrusion.GetDefinition);

		                  if iBossExtrusionDef <> nil then
                      begin
		      	            iExtrusionProperty := ksExtrusionParam(iBossExtrusionDef.ExtrusionParam); // интерфейс структуры параметров выдавливания
		                    iThinProperty := ksThinParam(iBossExtrusionDef.ThinParam); // интерфейс структуры параметров тонкой стенки

		      	            if (iExtrusionProperty <> nil) and (iThinProperty <> nil ) then
                        begin
   		      	            iBossExtrusionDef.SetSketch( iSketch2Entity ); // эскиз операции выдавливания
                          iExtrusionProperty.Direction := dtNormal; // направление выдавливания (прямое)
			                    iExtrusionProperty.TypeNormal := etBlind; // тип выдавливания ( строго на глубину )
			                    iExtrusionProperty.DepthNormal := 100; // глубина выдавливания
                          iThinProperty.Thin := false; // без тонкой стенки

                          iBossExtrusion.Create; // создадим операцию
                        end;
                      end;
                    end;
                  end;
                end;
              end;
            end;
          end;
        end;
      end;
    end;
  end;
  KGAX1.ZoomEntireDocument();

end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  KGAX1.ZoomEntireDocument();
end;


procedure TForm1.FormDestroy(Sender: TObject);
  var
    iKompas              : KompasObject;
begin
  iKompas := KGAX1.GetKompasObject;
  if iKompas <> nil then
  begin
    KGAX1.CloseAll;
    iKompas.Quit;
  end;

end;

procedure TForm1.RadioGroup1Click(Sender: TObject);
begin
  KGAX1.Document3DDrawMode := RadioGroup1.ItemIndex;
end;

end.
