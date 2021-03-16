  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ProcNavNode_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ProcNavNode_P.Out1_Y0
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ProcNavNode_P.Constant_Value
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ProcNavNode_P.Out1_Y0_h
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ProcNavNode_P.Constant_Value_g
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% ProcNavNode_P.Constant_Value_m
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ProcNavNode_P.Constant_Value_j
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ProcNavNode_P.Gain1_Gain
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ProcNavNode_P.Constant_Value_e
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ProcNavNode_P.Gain2_Gain
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ProcNavNode_P.Gain_Gain
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ProcNavNode_P.Gain1_Gain_g
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ProcNavNode_P.Gain_Gain_c
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ProcNavNode_P.Constant_Value_o
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ProcNavNode_P.Gain2_Gain_f
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 9;
	
	  ;% ProcNavNode_P.Gain1_Gain_c
	  section.data(11).logicalSrcIdx = 14;
	  section.data(11).dtTransOffset = 10;
	
	  ;% ProcNavNode_P.Gain_Gain_n
	  section.data(12).logicalSrcIdx = 15;
	  section.data(12).dtTransOffset = 11;
	
	  ;% ProcNavNode_P.Gain1_Gain_d
	  section.data(13).logicalSrcIdx = 16;
	  section.data(13).dtTransOffset = 12;
	
	  ;% ProcNavNode_P.Constant_Value_a
	  section.data(14).logicalSrcIdx = 17;
	  section.data(14).dtTransOffset = 13;
	
	  ;% ProcNavNode_P.Gain2_Gain_g
	  section.data(15).logicalSrcIdx = 18;
	  section.data(15).dtTransOffset = 14;
	
	  ;% ProcNavNode_P.DiscreteTimeIntegrator_gainval
	  section.data(16).logicalSrcIdx = 19;
	  section.data(16).dtTransOffset = 15;
	
	  ;% ProcNavNode_P.DiscreteTimeIntegrator_IC
	  section.data(17).logicalSrcIdx = 20;
	  section.data(17).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ProcNavNode_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ProcNavNode_B.In1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ProcNavNode_B.In1_l
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% ProcNavNode_B.VectorConcatenate
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ProcNavNode_B.Divide2
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 3;
	
	  ;% ProcNavNode_B.Divide
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 4;
	
	  ;% ProcNavNode_B.Divide1
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 5;
	
	  ;% ProcNavNode_B.Divide3
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 6;
	
	  ;% ProcNavNode_B.WorldPosition
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 7;
	
	  ;% ProcNavNode_B.MATLABSystem2_o1
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 10;
	
	  ;% ProcNavNode_B.MATLABSystem2_o2
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ProcNavNode_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ProcNavNode_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ProcNavNode_DW.obj_i
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ProcNavNode_DW.obj_b
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ProcNavNode_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% ProcNavNode_DW.Scope1_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ProcNavNode_DW.Scope1_PWORK_a.LoggedData
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ProcNavNode_DW.Scope6_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ProcNavNode_DW.Scope2_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ProcNavNode_DW.Scope_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% ProcNavNode_DW.IfActionSubsystem2_SubsysRanBC
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ProcNavNode_DW.IfActionSubsystem1_SubsysRanBC
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ProcNavNode_DW.IfActionSubsystem_SubsysRanBC
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ProcNavNode_DW.EnabledSubsystem_SubsysRanBC
	  section.data(4).logicalSrcIdx = 14;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ProcNavNode_DW.EnabledSubsystem_SubsysRanBC_k
	  section.data(5).logicalSrcIdx = 15;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1899617999;
  targMap.checksum1 = 3786400203;
  targMap.checksum2 = 542725709;
  targMap.checksum3 = 1884230669;

