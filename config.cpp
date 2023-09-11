class CfgPatches 
{
    class BB_Companion_Mod 
    {
        author="Brainless Ben"
        requiredAddons[]=
        {
            "A3_Animals_F_Beta"
        };
        requiredVersion=0.1;
        units[]=
        {
            "BB_Companion_IDAP",
            "BB_Companion_MC",
            "BB_Companion_MCA",
            "BB_Companion_MCT",
            "BB_Companion_MCW",
            "BB_Companion_MCB"
        };
        weapons[]={};
    };
};
class CfgMovesAnimal_Base_F
{
    class Default;
    class StandBase;
    class DefaultDie;
    class ManActions;
    class Actions
    {
        class NoActions;
    };
    class Interpolations;
    class BlendAnims;
};

class CfgMovesCompainon_Doggo: CfgMovesAnimal_Base_F
{
    acces=1;
    enableDirectControl=1;
    skeletonName="BB_Companion_Skeleton";
    collisionVertexPattern[]=
	{
		"1a",
		"2a",
		"3a",
		"4a",
		"5a",
		"6a",
		"7a",
		"8a",
		"9a",
		"10a",
		"11a",
		"12a",
		"13a",
		"14a",
		"15a",
		"16a",
		"17a",
		"18a",
		"19a",
		"20a",
		"21a",
		"22a",
		"23a",
		"24a",
		"25a",
		"26a"
	};
	collisionGeomCompPattern[]={1};
    class Default: Default
	{
		collisionShape="\Companion\BB_Companion_CollShape.p3d";
        actions="CompanionActions";
	};
    class StandBase: Default
	{
        actions="CompanionActions";
		aiming="aimingDefault";
		leaningFactorBeg=1;
		leaningFactorEnd=1;
        disableWeapons=1;
        disableWeaponsLong=1;
	};
	class DefaultDie: Default
	{
		aiming="aimingNo";
		legs="legsNo";
		head="headNo";
		disableWeapons=1;
		interpolationRestart=1;
		soundOverride="fallbody";
		soundEdge1=0.44999999;
		soundEdge2=0.44999999;
	};
    class States
    {
        class Companion_Idle_Stop: StandBase
        {
            enableDirectControl=1;
			actions="CompanionActions";
            file="\Companion\data\Anim\Companion_IdleStop";
			duty=-1;
			variantsAI[]=
			{
				"Companion_Idle_Stop",
				0.039999999,
				"Companion_Idle_Lie",
				0.039999999,
				"Companion_Idle_Sit02",
				0.039999999,
				"Companion_Idle_Sit03",
				0.039999999,
				"Companion_Idle_Sit04",
				0.039999999,
				"Companion_Idle_Sit05",
				0.039999999,
				"Companion_Idle_Sit06",
				0.039999999,
				"Companion_Idle_Sit07",
				0.039999999,
				"Companion_Idle_Sit08",
				0.039999999,
				"Companion_Idle_Bark",
				0.039999999,
				"Companion_Idle_Growl",
				0.039999999,
				"Companion_Idle_Walk",
				0.1,
				"Companion_Idle_Run",
				0.050000001,
				"Companion_Idle_Sprint",
				0.050000001
			};
			variantsPlayer[]={};
			variantAfter[]={3,6,9};
			speed=1e+010;
			relSpeedMin=0.69999999;
			relSpeedMax=1.1;
			looped=1;
			soundEnabled=0;
			connectTo[]=
			{
				"Companion_TurnL",
				0.1,
				"Companion_TurnR",
				0.1
			};
			interpolateTo[]=
			{
				"Companion_Idle_Stop",
				0.050000001,
				"Companion_Idle_01",
				0.050000001,
				"Companion_Idle_02",
				0.050000001,
				"Companion_Idle_03",
				0.050000001,
				"Companion_Idle_04",
				0.050000001,
				"Companion_Idle_05",
				0.050000001,
				"Companion_Idle_06",
				0.050000001,
				"Companion_Idle_07",
				0.050000001,
				"Companion_Idle_08",
				0.050000001,
				"Companion_Idle_09",
				0.050000001,
				"Companion_Idle_10",
				0.050000001,
				"Companion_Idle_Sit01",
				0.050000001,
				"Companion_Idle_Sit02",
				0.050000001,
				"Companion_Idle_Sit03",
				0.050000001,
				"Companion_Idle_Sit04",
				0.050000001,
				"Companion_Idle_Sit05",
				0.050000001,
				"Companion_Idle_Sit06",
				0.050000001,
				"Companion_Idle_Sit07",
				0.050000001,
				"Companion_Idle_Sit08",
				0.050000001,
				"Companion_Idle_Bark",
				0.050000001,
				"Companion_Idle_Growl",
				0.050000001,
				"Companion_Idle_Walk",
				0.2,
				"Companion_Idle_Run",
				0.02,
				"Companion_Idle_Sprint",
				0.02,
				"Companion_Die",
				0.2,
				"Companion_Walk",
				0.5,
				"Companion_Run",
				0.5,
				"Companion_Sprint",
				0.5,
				"Companion_Sit",
				0.5,
				"Companion_Stop",
				0.5,
				"Companion_TurnL",
				0.1,
				"Companion_TurnR",
				0.1
			};
			preload=1;
        };
        class Companion_TurnL: Companion_Idle{};
        class Companion_TurnR: Companion_TurnL{};
    };
    class Actions: Actions
    {
        class NoActions: NoActions
		{
			turnSpeed=8;
			limitFast=5.5;
			useFastMove=0;
			upDegree=0;
		};//TODO CHANGE NAMES
        class CompanionActions: NoActions
        {
            Stop="Companion_Idle_Stop";
			StopRelaxed="Companion_Idle_Stop";
			TurnL="Companion_TurnL";
			TurnR="Companion_TurnR";
			TurnLRelaxed="Companion_TurnL";
			TurnRRelaxed="Companion_TurnR";
			Default="Companion_Idling";
			JumpOff="Companion_Idle_Stop";
			WalkF="Companion_Idle_Walk";
			SlowF="Companion_Idle_Run";
			FastF="Companion_Idle_Sprint";
			EvasiveForward="Companion_Idle_Sprint";
			Down="Companion_Idle_Stop";
			Up="Companion_Idle_Stop";
			PlayerStand="Companion_Idle_Stop";
			PlayerProne="Companion_Idle_Stop";
			PlayerCrouch="Companion_Idle_Sitting";
			Crouch="Companion_Idle_Sitting";
			Lying="Companion_Idle_Stop";
			Stand="Companion_Idle_Stop";
			Combat="Companion_Idle_Stop";
			CanNotMove="Companion_Idle_Stop";
			Civil="Companion_Idle_Stop";
			CivilLying="Companion_Idle_Stop";
			FireNotPossible="Companion_Idle_Stop";
			Die="Companion_Die";
			turnSpeed=8;
			limitFast=5.5;
			useFastMove=0;
			upDegree="ManPosNoWeapon";
        };
        class FinRun: CompanionActions
		{
			Die="Companion_Die_Run";
		};
		class FinSprint: CompanionActions
		{
			FastF="Companion_Idle_Sprint";
			EvasiveForward="Companion_Idle_Sprint";
			Die="Companion_Die_Sprint";
			turnSpeed=8;
			limitFast=5.5;
			useFastMove=1;
		};
		class FinSit: CompanionActions
		{
			Stop="Companion_Idle_Sitting";
			StopRelaxed="Companion_Idle_Sitting";
			Die="Companion_Die_Sit";
		};
		class FinForceStop: CompanionActions
		{
			CivilLying="Companion_Stop";
		};
		class FinForceSit: FinSit
		{
			CivilLying="Companion_Sit";
		};
		class FinForceWalk: CompanionActions
		{
			CivilLying="Companion_Walk";
		};
		class FinForceRun: FinRun
		{
			CivilLying="Companion_Run";
		};
		class FinForceSprint: FinSprint
		{
			CivilLying="Companion_Sprint";
		};
    };
    class Interpolations
	{
	};
	transitionsInterpolated[]={};
	transitionsSimple[]={};
	transitionsDisabled[]={};
	class BlendAnims: BlendAnims
	{
		aimingDefault[]=
		{
			"head",
			1,
			"head",
			1,
			"head",
			1
		};
		untiltWeaponDefault[]={};
		legsDefault[]={};
		headDefault[]={};
		aimingNo[]={};
		legsNo[]={};
		headNo[]={};
		aimingUpDefault[]={};
	};
};
