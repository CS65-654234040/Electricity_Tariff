#include <stdio.h>
#include <conio.h>

float mount(int m);
float cal1(float use);
float bill,ft=0.9343;
float re(float onp,float peak,float ofp,float offpeak);
float Reactive_Power(float des,float uses);
float Medium_General_TOU(float peaks,float offpeaks,float des);
float Small_General_CAL(float ele);
float Medium_General_Service_TOU();
float Large_General_Service_TOU();
float Specific_Normal();
float Specific_TOU_cal(float peaks,float peaks1,float offpeaks);
float Small_General_TOU(float peaks,float offpeaks,float service);
float Large_TOD(float peak,float pp,float offpeak,float rp);
float Large_TOU(float peak,float pp,float offpeak,float rp);
float Specific_Normal_cal(float peak,float peak2,float offpeak);
float Government_Normal_cal(float ele);
float Government_TOU_cal(float peak,float peak1,float offpeak);
float WATERc_TOU_cal(float peaks,float peaks1,float offpeaks);

main() 
{
	char ch;
	do{
		Electricity_Tariff();
		printf("Agin (Y/N)");
		ch = getche();
	}while (ch== 'y' || ch=='Y');
}
Electricity_Tariff()
{
	int choice;
	printf("Electricity Tariff Select Menu\n\n");
	printf("1. Residentail Service\n");
	printf("2. Small General Service\n");
	printf("3. Medium General Service\n");
	printf("4. Large General Service\n");
	printf("5. Specific Business Service\n");
	printf("6. Government Institutions and non-profit organization\n");
	printf("7. WATER PUMPING FOR AGRICULTURAL PURPOSES\n");
	printf("8. Temporary Tariff\n\n");	
	printf("\nElectricity Tariff : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("\nSelect Residentail Service\n\n");
            printf("1. Residentail Service (Normal Tariff / Progressive Rate)\n");
            printf("2. Residentail Service (TOU tariff)\n\n");
            printf("Residentail Service : ");
            scanf("%d",&choice);
            if(choice==1){
                Residentail_Service_Normal();
            }else if(choice==2){
                Residentail_Service_TOU();
            }
            break;
        case 2:
            printf("\nSelect Small General Service\n\n");
            printf("1. Small General Service (Normal Tariff / Progressive Rate)");
            printf("\n2. Small General Service (TOU tariff)\n\n");
            printf("Small General Service : ");
            scanf("%d",&choice);
            if(choice==1){
                Small_General_Service_Normal();
            }else if(choice==2){
                Small_General_Service_TOU();
            }
            break;
        case 3:
            printf("\nSelect Medium General Service\n\n");
            printf("1. Medium General Service(Normal Tariff / Progressive Rate)");
            printf("\n2. Medium General Service (TOU tariff)\n\n");
            printf("Medium General Service : ");
            scanf("%d",&choice);
            if(choice==1){
                Medium_General_Service_Normal();
            }else if(choice==2){
                Medium_General_Service_TOU();
            }
            break;
        case 4:
            printf("\nSelect Large General Service\n\n");
            printf("1. Large General Service (TOD Tariff )");
            printf("\n2. Large General Service (TOU tariff)\n\n");
            printf("Large General Service : ");
            scanf("%d",&choice);
            if(choice==1){
                Large_General_Service_TOD();
            }else if(choice==2){
                Large_General_Service_TOU();
            }
            break;
        case 5:
            printf("\nSelect Specific Business Service\n\n");
            printf("1. Specific Business Service (Normal Tariff)");
            printf("\n2. Specific Business Service (TOU tariff)\n\n");
            printf("Specific Business Service : ");
            scanf("%d",&choice);
            if(choice==1){
                Specific_Normal();
            }else if(choice==2){
                Specific_TOU();
            }
            break;
        case 6:
            printf("\nSelect Government Institutions Service\n\n");
            printf("1. Government Institutions and non-profit organization (Normal Tariff)");
            printf("\n2. Government Institutions and non-profit organization (TOU Tariff)\n\n");
            printf("Government Institutions Service : ");
            scanf("%d",&choice);
            if(choice==1){
                Government_Normal();
            }else if(choice==2){
                Government_TOU();
            }
            break;
        case 7:
        	printf("\nSelect WATER PUMPING FOR AGRICULTURAL PURPOSES \n\n");
            printf("1. WATER PUMPING FOR AGRICULTURAL PURPOSES (Normal tariff)");
            printf("\n2. WATER PUMPING FOR AGRICULTURAL PURPOSES (TOU tariff)\n\n");
            printf("WATER PUMPING FOR AGRICULTURAL PURPOSES : ");
            scanf("%d",&choice);
            if(choice==1){
                WATER_Normal();
            }else if(choice==2){
            	WATERc_TOU();
			}
			break;
		case 8:
			printf("\nTemporary Tariff \n\n");
			Temporary_Tariff();
			}	
}
Residentail_Service_Normal()
{
	int m;
	int choice,y;
	float bill,service,use,eu=0.9343,total,tax;
	printf("\nMenu\n");
	printf("\n1. Normal tariff with consumption not exceeding 150 kWh per month\n");
	printf("2. Normal tariff with consumption exceeding 150 kWh per month\n");
	printf("\nCustomer Type : ");
	scanf("%d",&choice);
	if(choice==1){
		service=8.19;
		year(y);
		printf("\n              Customer Used Energy :  ");
		scanf("%f",&use);
		printf("1.1.1 Normal tariff with consumption not exceeding 150 kWh per month\n");
		printf("       Section 1 Base Tariff\n");	
		printf("            	Energy Charge      	%.2f   Baht\n",cal1(use));	
		printf("       		Service Charge     	  %.2f   Baht\n",service);
		printf("       		Total Base Tariff  	%.2f   Baht\n",cal1(use)+service);	
		printf("       Section 2 (Ft) Charge\n");
		eu=ft*use;
		printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
		printf("       Section 3 Tax 7%\n");
		tax = ((cal1(use)+service)+eu)*7/100;
		printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
		total = (cal1(use)+service)+eu+tax;
		printf("       Total Electricity Charge          %.2f   Baht\n",total);
	}else if(choice==2){
		service= 24.62; 
		year(y);
		printf("\n              Customer Used Energy :  ");
		scanf("%f",&use);
        if (use >= 0 && use <= 150){
            bill = use * 3.2484;
        }else if (use >= 151 && use <= 400){
            bill = 150 * 3.2484 + (use - 150) * 4.2218;
        }else{
            bill = 150 * 3.2484 + 250 * 4.2218 + (use - 250) * 4.4217;
        }
		printf("1.1.2 Normal tariff with consumption exceeding 150 kWh per month\n");
		printf("       Section 1 Base Tariff\n");	
		printf("            	Energy Charge      %.2f   Baht\n",bill);	
		printf("       		Service Charge     %.2f   Baht\n",service);
		printf("       		Total Base Tariff  %.2f   Baht\n",bill+service);	
		printf("       Section 2 (Ft) Charge\n");
		eu=ft*use;
		printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
		printf("       Section 3 Tax 7%\n");
		tax= ((bill+service)+eu)*7/100;
		printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
		total=(bill+service)+eu+tax;
		printf("       Total Electricity Charge          %.2f   Baht\n",total);	
	}
}
float cal1(float use)
{
struct multiply{
	float m1,m2,m3,m4,m5,m6,m7;
};
	 	struct multiply m = {2.3488, 2.9882, 3.2405, 3.6237, 3.7171, 4.2218, 4.4217};
		float bill;
	     if (use <= 15) {
	        bill = use * m.m1;
	    }
	    else if (use <= 25) {
	        bill = 15 * m.m1 + (use - 15) * m.m2;
	    }
	    else if (use <= 35) {
	        bill = 15 * m.m1 + 10 * m.m2 + (use - 25) * m.m3;
	    }
	    else if (use <= 100) {
	        bill = 15 * m.m1 + 10 * m.m2 + 10 * m.m3 + (use - 35) * m.m4;
	    }
	    else if (use <= 150) {
	        bill = 15 * m.m1 + 10 * m.m2 + 10 * m.m3 + 65 * m.m4 + (use - 100) * m.m5;
	    }
	    else if (use <= 400) {
	        bill = 15 * m.m1 + 10 * m.m2 + 10 * m.m3 + 65 * m.m4 + 50 * m.m5 + (use - 150) * m.m6;
	    }
	    else {
	        bill = 15 * m.m1 + 10 * m.m2 + 10 * m.m3 + 65 * m.m4 + 50 * m.m5 + 250 * m.m6 + (use - 400) * m.m7;
	    }
	    return (bill);
}
Residentail_Service_TOU()
{
    int choice,y,Vol;
    float use,peak,offpeak,holiday,service,eu=0.9343,total,tax;
    printf("Select Voltage\n");
    printf("1. Voltage 22 - 33 kV\n");
    printf("2. Voltage below 22 kV22\n");
    printf("Select : ");
    scanf("%d",&Vol);
    switch (Vol) {
        case 1:
            service = 312.24;
            year(y);
            printf("\nUsed Energy during On Peak Period  : ");
            scanf("%f",&peak);
            printf("Used Energy during Off Peak Period : ");
            scanf("%f",&offpeak);
            printf("Residentail Service (TOU tariff)\n");
            printf("       Section 1 Base Tariff\n");
            total=(peak*5.1135)+(offpeak*2.6037 );
            printf("             Energy Charge      %.2f   Baht\n",total);
            printf("             Service Charge     %.2f   Baht\n",service);
            printf("             Total Base Tariff  %.2f   Baht\n",total+service);
            printf("       Section 2 (Ft) Charge\n");
            total=total+service;
            eu = (peak+offpeak)*ft;
            printf("             Used Energy x Ft Rate       %.2f   Baht\n",eu);
            printf("       Section 3 Tax 7%\n");
            tax = (total+eu)*7/100;
            printf("             (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
            bill=total+eu+tax;
            printf("       Total Electricity Charge          %.2f   Baht\n",bill);
            break;
        case 2:
            service = 24.62;
            year(y);
            printf("\nUsed Energy during On Peak Period  : ");
            scanf("%f",&peak);
            printf("Used Energy during Off Peak Period : ");
            scanf("%f",&offpeak);
            printf("Residentail Service (TOU tariff)\n");
            printf("       Section 1 Base Tariff\n");
            total=(peak*5.1135)+(offpeak*2.6037 );
            printf("             Energy Charge      %.2f   Baht\n",total);
            printf("             Service Charge     %.2f   Baht\n",service);
            printf("             Total Base Tariff  %.2f   Baht\n",total+service);
            printf("       Section 2 (Ft) Charge\n");
            total=total+service;
            eu = (peak+offpeak)*ft;
            printf("             Used Energy x Ft Rate       %.2f   Baht\n",eu);
            printf("       Section 3 Tax 7%\n");
            tax = (total+eu)*7/100;
            printf("             (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
            bill=total+eu+tax;
            printf("       Total Electricity Charge          %.2f   Baht\n",bill);
            break;

        default:
            printf("Invalid option.\n");
            break;
    }
}
Small_General_Service_Normal()
{
	int Vol,y;
	float vat,de,use,rp,total,service=312.24,eu,peak,offpeak,mpeak,moffpeak,tax;
	printf("Select Voltage\n");
	printf("1. Voltage 22 - 33 kV\n");
	printf("2. Voltage lower than 22 kilovolts\n");
	printf("Select : ");
	scanf("%d",&Vol);
	if(Vol==1){
		Small_General_CAL(3.9086);
	}else if(Vol==2){
		service=33.29;
		year(y);
		printf("\n              Customer Used Energy :  ");
		scanf("%f",&use);
		if (use >= 0 && use <= 150){
            total = use * 3.2484;
        }else if (use >= 151 && use <= 400){
            total = 150 * 3.2484 + (use - 150) * 4.2218;
        }else{
            total = 150 * 3.2484 + 250 * 4.2218 + (use - 400) * 4.4217;
        }		
		printf("       Section 1 Base Tariff\n");		
		printf("       		Service Charge     %.2f   Baht\n",service);
		printf("       		Total Base Tariff  %.2f   Baht\n",total);	
		printf("       Section 2 (Ft) Charge\n");
		eu=ft*use;
		printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
		printf("       Section 3 Tax 7%\n");
		tax= (total+eu)*7/100;
		printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
		bill=(total+service)+eu+tax;
		printf("       Total Electricity Charge          %.2f   Baht\n",bill);		
	}
}
float Small_General_CAL(float ele)
{
	int Vol,y;	
	float vat,de,use,rp,total,service=312.24,eu,peak,offpeak,mpeak,moffpeak,tax;
	year(y);
	printf("\n              Customer Used Energy :  ");
	scanf("%f",&use);
	total=use*ele;
	printf("       Section 1 Base Tariff\n");	
	printf("       		Service Charge     	 %.2f   Baht\n",service);
	printf("       		Total Base Tariff  	%.2f   Baht\n",total+service);
	printf("       Section 2 (Ft) Charge\n");
	eu = ft*use;
    printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
	printf("       Section 3 Tax 7%\n");
	tax = (total+eu)*7/100;
	printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
	bill = (total+service)+eu+tax;
	printf("       Total Electricity Charge          %.2f   Baht\n",bill);	
}
Small_General_Service_TOU()
{
	int choice,y,Vol;
	float use,peak,offpeak,service,eu=0.9343,total;
	printf("Select Voltage\n");
	printf("1. Voltage 22 - 33 kV\n");
	printf("2. Voltage below 22 kV22\n");
	printf("Select : ");
	scanf("%d",&Vol);
	if(Vol==1){
		Small_General_TOU(5.1135,2.6037,312.24);
	}if(Vol==2){
		Small_General_TOU(5.7982,2.6369,33.29);
	}
}
float Small_General_TOU(float peaks,float offpeaks,float service)
{
	int y;
	float vat,de,use,rp,total,eu,peak,offpeak,mpeak,moffpeak,tax;
	year(y);
	printf("\nUsed Energy during On Peak Period  : ");
	scanf("%f",&peak);
	printf("Used Energy during Off Peak Period : ");
	scanf("%f",&offpeak);
	total=(peak*peaks)+(offpeak*offpeaks);
	printf("       Section 1 Base Tariff\n");
	printf("       		Service Charge     %.2f   Baht\n",service);
	printf("       		Total Base Tariff  %.2f   Baht\n",total+service);
	printf("       Section 2 (Ft) Charge\n");
	eu = ft*(peak+offpeak);
    printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
	printf("       Section 3 Tax 7%\n");
	tax = ((total+service)+eu)*7/100;
	printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
	bill = (total+service)+eu+tax;
	printf("       Total Electricity Charge          %.2f   Baht\n",bill);				
}
Medium_General_Service_Normal()
{
	int Vol,y;
	float de,use,rp,total,service=312.24,eu;
	printf("Select Voltage\n");
	printf("1. Voltage from 69 kV and above\n");
	printf("2. Voltage 22 - 33 kV\n");
	printf("3. Voltage lower than 22 kilovolts\n");
	printf("Select : ");
	scanf("%d",&Vol);
	if(Vol==1){
		year(y);
		Reactive_Power(175.70,3.1097);
	}else if(Vol==2){
		year(y);
		Reactive_Power(196.26,3.1471);
	}else if(Vol==3){
		year(y);
		Reactive_Power(221.50,3.1751);
	}	
}
float Reactive_Power(float des,float uses)
{
	float de,use,rp,total,service=312.24,eu,rps,tax;
	printf("\nMaximum Electrical Power Demand : ");
	scanf("%f",&de);
	printf("              Used Reactive Power : ");
	scanf("%f",&rp);
	printf("             Customer Used Energy : ");
	scanf("%f",&use);
	if(rp==1){
			total = (de*des)+(use*uses);
			printf("       Section 1 Base Tariff\n");
		    printf("       		Service Charge     %.2f   Baht\n",service);
		    printf("       		Total Base Tariff  %.2f   Baht\n",total+service);
		    printf("       Section 2 (Ft) Charge\n");
		    total=total+service;
		    eu=use*ft;
		    printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
			tax = (total+eu)*7/100;
			printf("       Section 3 Tax 7%\n");
			printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
			bill=total+eu+tax;
			printf("       Total Electricity Charge          %.2f   Baht\n",bill);	
		}else if(rp>1){
			rp= (rp-1)*56.07;
			total = (de*des)+(use*uses);
			printf("       Section 1 Base Tariff\n");
		    printf("       		Service Charge     %.2f   Baht\n",service);
		    printf("       		Total Base Tariff  %.2f   Baht\n",total+rp+service);
		    printf("       Section 2 (Ft) Charge\n");
		    total=total+rp+service;
		    eu=use*tax;
		    printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
			tax = (total+eu)*7/100;
			printf("       Section 3 Tax 7%\n");
			printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
			bill=total+eu+tax;
			printf("       Total Electricity Charge          %.2f   Baht\n",bill);
		}
}
float Medium_General_Service_TOU()
{
	int Vol,y;
	float vat,de,use,rp,total,service=312.24,eu,peak,offpeak,mpeak,moffpeak,tax;
	printf("Select Voltage\n");
	printf("1. Voltage from 69 kV and above\n");
	printf("2. Voltage 22 - 33 kV\n");
	printf("3. Voltage lower than 22 kilovolts\n");
	printf("Select : ");
	scanf("%d",&Vol);
	if(Vol==1){
		year(y);
		Medium_General_TOU(4.1025,2.5849,74.14);
	}else if(Vol==2){
		year(y);
		Medium_General_TOU(4.1839,2.6037,132.93);
	}else if(Vol==3){
		year(y);
		Medium_General_TOU(4.3297,2.6369,210.00);		
	}	
}
float Medium_General_TOU(float peaks,float offpeaks,float des)
{

	float vat,de,use,rp,total,service=312.24,eu,peak,offpeak,mpeak,moffpeak,tax;
	printf("\nMax On Peak Period  : ");
	scanf("%f",&mpeak);
	printf("Max Off Peak Period : ");
	scanf("%f",&moffpeak);
	printf("\nUsed Energy during On Peak Period  : ");
	scanf("%f",&peak);
	printf("Used Energy during Off Peak Period : ");
	scanf("%f",&offpeak);
	printf("              Used Reactive Power : ");
	scanf("%f",&rp);
	if(rp==1){
			total=(mpeak*peaks)+(moffpeak*offpeaks);
			printf("       Section 1 Base Tariff\n");
		    printf("       		Service Charge     %.2f   Baht\n",service);
		    printf("       		Total Base Tariff  %.2f   Baht\n",total+service);
		    printf("       Section 2 (Ft) Charge\n");
		    total=total+service;
		    eu=rp*ft;
		    printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
			tax = (total+eu)*7/100;
			printf("       Section 3 Tax 7%\n");
			printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
			bill=total+eu+tax;
			printf("       Total Electricity Charge          %.2f   Baht\n",bill);	
		}else if(rp>1){
			rp= (rp-1)*56.07;
			total=(mpeak*peaks)+(moffpeak*offpeaks);
			printf("       Section 1 Base Tariff\n");
		    printf("       		Service Charge     %.2f   Baht\n",service);
		    printf("       		Total Base Tariff  %.2f   Baht\n",total+rp+service);
		    printf("       Section 2 (Ft) Charge\n");
		    total=total+rp+service;
		    eu=rp*ft;
		    printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
			tax = (total+eu)*7/100;
			printf("       Section 3 Tax 7%\n");
			printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
			bill=total+eu+tax;
			printf("       Total Electricity Charge          %.2f   Baht\n",bill);
		}	
}
Large_General_Service_TOD()
{
	int Vol,y;
	float vat,de,use,rp,total,service=312.24,eu,ft=0.9343,peak,offpeak,mpeak,moffpeak,mpp,pp;
	printf("Select Voltage\n");
	printf("1. Voltage from 69 kV and above\n");
	printf("2. Voltage 22 - 33 kV\n");
	printf("3. Voltage lower than 22 kilovolts\n");
	printf("Select : ");
	scanf("%d",&Vol);
	if(Vol==1){	
		year(y);
		Large_TOD(224.30,29.91,0,3.1097);
	}else if(Vol==2){	
		year(y);
		Large_TOD(285.05,58.88,0,3.1471);
	}else if(Vol==3){	
		year(y);
		Large_TOD(332.71,68.22,0,3.1751);
	}
}
float Large_TOD(float peak,float pp,float offpeak,float rp)
{
	int Vol,y;
	float vat,de,use,total,service=312.24,eu,mpeak,moffpeak,mpp,mrp,tax;
	printf("\nUsed Demand during On Peak Period : ");
	scanf("%f",&mpeak);
	printf("Used Demand during Partial Peak : ");
	scanf("%f",&mpp);
	printf("\nUsed Demand during Off Peak Period  : ");
	scanf("%f",&moffpeak);
	printf("Used Reactive Power : ");
	scanf("%f",&mrp);
	printf("              Customer Used Energy : ");
	scanf("%f",&use);
	total=(mpeak*peak)+(mpp*pp)+(moffpeak*offpeak)+(mrp*rp);
	printf("       Section 1 Base Tariff\n");
	printf("       		Service Charge     %.2f   Baht\n",service);
	printf("       		Total Base Tariff  %.2f   Baht\n",total+service);
	printf("       Section 2 (Ft) Charge\n");
	eu = use*ft;
	printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
	printf("       Section 3 Tax 7%\n");
	tax = (total+ft)*7/100;
	printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
	bill=total+eu+tax;
	printf("       Total Electricity Charge          %.2f   Baht\n",bill);		
}
float Large_General_Service_TOU()
{
	int Vol,y;
	float vat,de,use,rp,total,service=312.24,eu,peak,offpeak,mpeak,moffpeak,mpp,pp;
	printf("Select Voltage\n");
	printf("1. Voltage from 69 kV and above\n");
	printf("2. Voltage 22 - 33 kV\n");
	printf("3. Voltage lower than 22 kilovolts\n");
	printf("Select : ");
	scanf("%d",&Vol);
	if(Vol==1){	
		year(y);
		Large_TOU(74.14,4.1025 ,2.5849,3.1097);
	}else if(Vol==2){	
		year(y);
		Large_TOU(132.93,4.1839,2.6037,3.1471);
	}else if(Vol==3){	
		year(y);
		Large_TOU(210.00,4.3297 ,2.6369,3.1751);	
	}
}

float Large_TOU(float peak,float offpeak,float pp,float rp)
{
	int Vol,y;
	float vat,de,use,total,service=312.24,eu,mpeak,moffpeak,mpp,mrp,tax;
	printf("\nMax On Peak Period  : ");
	scanf("%f",&mpeak);
	printf("Max Off Peak Period : ");
	scanf("%f",&moffpeak);
	printf("\nUsed Energy during On Peak Period  : ");
	scanf("%f",&peak);
	printf("Used Energy during Off Peak Period : ");
	scanf("%f",&offpeak);
	printf("              Used Reactive Power : ");
	scanf("%f",&mrp);
	printf("             Customer Used Energy : ");
	scanf("%f",&use);
	total=(mpeak*peak)+(moffpeak*offpeak)+((mrp-1)*56.07*rp);
	printf("       Section 1 Base Tariff\n");
	printf("       		Service Charge     %.2f   Baht\n",service);
	printf("       		Total Base Tariff  %.2f   Baht\n",total+service);
	printf("       Section 2 (Ft) Charge\n");
	eu = use*ft;
	printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
	printf("       Section 3 Tax 7%\n");
	tax = (total+tax)*7/100;
	printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
	bill=total+eu+tax;
	printf("       Total Electricity Charge          %.2f   Baht\n",bill);
}
float Specific_Normal()
{
	int Vol,y;
	float vat,de,use,rp,total,service=312.24,eu,peak,offpeak,mpeak,moffpeak;
	printf("Select Voltage\n");
	printf("1. Voltage from 69 kV and above\n");
	printf("2. Voltage 22 - 33 kV\n");
	printf("3. Voltage lower than 22 kilovolts\n");
	printf("Select : ");
	scanf("%d",&Vol);
	if(Vol==1){
		year(y);
		Specific_Normal_cal(74.14,4.1025,2.5849);
	}else if(Vol==2){
		year(y);
		Specific_Normal_cal(132.93,4.1839,2.6037);
	}else if(Vol==3){
		year(y);
		Specific_Normal_cal(210.00,4.3297,2.6369);
	}	
}
float Specific_Normal_cal(float peak,float peak2,float offpeak)
{	
	int Vol,y;
	float vat,de,use,rp,total,service=312.24,eu,mpeak,moffpeak,tax;
	printf("\nMAX Demand during  : ");
	scanf("%f",&de);
	printf("              Used Reactive Power : ");
	scanf("%f",&rp);
	printf("             Customer Used Energy : ");
	scanf("%f",&use);
	total = (de*peak)+((rp-1)*56.07);
	printf("       Section 1 Base Tariff\n");
	printf("       		Service Charge     %.2f   Baht\n",service);
	printf("       		Total Base Tariff  %.2f   Baht\n",total+service);
	printf("       Section 2 (Ft) Charge\n");
	eu=use*ft;
	printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
	tax = ((total+service)+eu)*7/100;
	printf("       Section 3 Tax 7%\n");
	printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
	bill=(total+service)+eu+tax;
	printf("       Total Electricity Charge          %.2f   Baht\n",bill);	
}
Specific_TOU()
{
	int Vol,y;
	float vat,rp,de,use,total,service=312.24,eu,mpeak,moffpeak,mpp,mrp,peak,offpeak,tax;		
	printf("Select Voltage\n");
	printf("1. Voltage from 69 kV and above\n");
	printf("2. Voltage 22 - 33 kV\n");
	printf("3. Voltage lower than 22 kilovolts\n");
	printf("Select : ");
	scanf("%d",&Vol);
	if(Vol==1){
		year(y);
		Specific_TOU_cal(74.14,4.1025,2.5849);
	}else if(Vol==2){
		year(y);
		Specific_TOU_cal(132.93,4.1839,2.6037);
	}else if(Vol==3){
		year(y);
		Specific_TOU_cal(210.00,4.3297,2.6369);
	}		
}
float Specific_TOU_cal(float peaks,float peaks1,float offpeaks)
{
	int Vol,y;
	float vat,rp,de,use,total,service=312.24,eu,mpeak,moffpeak,mpp,mrp,peak,offpeak,tax;	
	printf("\nUsed Demand during On Peak Period : ");
	scanf("%f",&mpeak);
	printf("Used Demand during Off Peak Period : ");
	scanf("%f",&moffpeak);
	printf("\nUsed Energy during On Peak Period : ");
	scanf("%f",&peak);
	printf("Used Energy during Off Peak Period : ");
	scanf("%f",&offpeak);
	printf("              Used Reactive Power : ");
	scanf("%f",&rp);
	printf("              Customer Used Energy : ");
	scanf("%f",&use);
	total=((mpeak+moffpeak)*peak)+((rp-1)*56.07);
	printf("       Section 1 Base Tariff\n");
	printf("       		Service Charge     %.2f   Baht\n",service);
	printf("       		Total Base Tariff  %.2f   Baht\n",total+service);
	printf("       Section 2 (Ft) Charge\n");
	eu=use*ft;
	printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
	tax = ((total+service)+eu)*7/100;
	printf("       Section 3 Tax 7%\n");
	printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
	bill=(total+service)+eu+tax;
	printf("       Total Electricity Charge          %.2f   Baht\n",bill);					
}
Government_Normal()
{
	int Vol,y;
	float vat,rp,de,use,total,service=312.24,eu,mpeak,moffpeak,mpp,mrp,peak,offpeak,tax;		
	printf("Select Voltage\n");
	printf("1. Voltage from 69 kV and above\n");
	printf("2. Voltage 22 - 33 kV\n");
	printf("3. Voltage lower than 22 kilovolts\n");
	printf("Select : ");
	scanf("%d",&Vol);
	if(Vol==1){
		year(y);
		Government_Normal_cal(3.4149);
	}else if(Vol==2){
		year(y);
		Government_Normal_cal(3.5849);
	}else if(Vol==3){
		year(y);
		printf("\n");
		printf("             Customer Used Energy : ");
		scanf("%f",&use);
		if(use<=10){
			total = use *2.8013;
		}else if(use>10){
			total = 10 * 2.8013 +(use -10 )*3.8919;
		}	
		printf("       Section 1 Base Tariff\n");
		printf("       		Service Charge     %.2f   Baht\n",service);
		printf("       		Total Base Tariff  %.2f   Baht\n",total+service);
		printf("       Section 2 (Ft) Charge\n");
		eu = use*ft;
		printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
		printf("       Section 3 Tax 7%\n");
		tax = ((total+service)+eu)*7/100;
		printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
		bill= (total+service)+eu+tax;
		printf("       Total Electricity Charge          %.2f   Baht\n",bill);				
	}			
}
float Government_Normal_cal(float ele)
{
	int Vol,y;
	float vat,rp,de,use,total,service=312.24,eu,mpeak,moffpeak,mpp,mrp,peak,offpeak,tax;	
	printf("\n");
	printf("             Customer Used Energy : ");
	scanf("%f",&use);	
    total = use * ele;
	printf("       Section 1 Base Tariff\n");
	printf("       		Service Charge     %.2f   Baht\n",service);
	printf("       		Total Base Tariff  %.2f   Baht\n",total+service);
	printf("       Section 2 (Ft) Charge\n");
	eu = use*ft;
	printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
	printf("       Section 3 Tax 7%\n");
	tax = ((total+service)+eu)*7/100;
	printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
	bill= (total+service)+eu+tax;
	printf("       Total Electricity Charge          %.2f   Baht\n",bill);			
}
Government_TOU()
{	
	int Vol,y;
	float vat,de,use,rp,total,service=312.24,eu,peak,offpeak,mpeak,moffpeak,mpp,pp,mrp;
	printf("Select Voltage\n");
	printf("1. Voltage from 69 kV and above\n");
	printf("2. Voltage 22 - 33 kV\n");
	printf("3. Voltage lower than 22 kilovolts\n");
	printf("Select : ");
	scanf("%d",&Vol);
	if(Vol==1){
		year(y);
		Government_TOU_cal(74.14,4.1025,2.5849);
	}else if(Vol==2){
		year(y);
		Government_TOU_cal(132.93,4.1839,2.6037);
	}else if(Vol==3){
		year(y);
		Government_TOU_cal(210.00,4.3297,2.6369);
	}	
			
}
float Government_TOU_cal(float peaks,float peak1,float offpeaks)
{
	int Vol,y;
	float vat,de,use,rp,total,service=312.24,eu,mpeak,moffpeak,mpp,pp,mrp,tax,peak,offpeak;	
	printf("\nMax On Peak Period  : ");
	scanf("%f",&mpeak);
	printf("Max Off Peak Period : ");
	scanf("%f",&moffpeak);
	printf("\nUsed Energy during On Peak Period  : ");
	scanf("%f",&peak);
	printf("Used Energy during Off Peak Period : ");
	scanf("%f",&offpeak);
	printf("              Used Reactive Power : ");
	scanf("%f",&mrp);
	printf("             Customer Used Energy : ");
	scanf("%f",&use);
	total=((mpeak+moffpeak)*peak)+((rp-1)*56.07);
	printf("       Section 1 Base Tariff\n");
	printf("       		Service Charge     %.2f   Baht\n",service);
	printf("       		Total Base Tariff  %.2f   Baht\n",total+service);
	printf("       Section 2 (Ft) Charge\n");
	eu=use*ft;
	printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
	tax = ((total+service)+eu)*7/100;
	printf("       Section 3 Tax 7%\n");
	printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
	bill=(total+service)+eu+tax;
	printf("       Total Electricity Charge          %.2f   Baht\n",bill);	
}
WATER_Normal()
{
	int Vol,y;
	float vat,de,use,total,service=115.16,eu,mpeak,moffpeak,mpp,mrp,tax;
	year(y);
	printf("\n");
	printf("             Customer Used Energy : ");	
	scanf("%f",&use);
	if(use<=100){
		total = use * 2.0889;
	}else if (use>100){
		total = 100*2.0889 +(use -100)* 3.2405;
	}
	printf("       Section 1 Base Tariff\n");
	printf("       		Service Charge     %.2f   Baht\n",service);
	printf("       		Total Base Tariff  %.2f   Baht\n",total+service);
	printf("       Section 2 (Ft) Charge\n");
	eu = use*0.9343;
	printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
	printf("       Section 3 Tax 7%\n");
	tax = ((total+service)+eu)*7/100;
	printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
	bill=(total+service)+eu+tax;
	printf("       Total Electricity Charge          %.2f   Baht\n",bill);	
	
}
WATERc_TOU()
{
	int Vol,y;
	float vat,de,use,rp,total,service=204.07,eu,peak,offpeak,mpeak,moffpeak,mpp,pp,mrp;
	printf("Select Voltage\n");
    printf("1. Voltage 22 - 33 kV\n");
    printf("2. Voltage below 22 kV22\n");
    printf("Select : ");
    scanf("%d",&Vol);
    if(Vol==1){
    	year(y);
		WATERc_TOU_cal(132.93,4.1839,2.6037);	
	}else if (Vol==2){
		year(y);
		WATERc_TOU_cal(210.00,4.3297,2.6369);
	}
	

}
float WATERc_TOU_cal(float peaks,float peaks1,float offpeaks)
{
	int Vol,y;
	float vat,de,use,rp,total,service=204.07,eu,peak,offpeak,mpeak,moffpeak,mpp,pp,mrp,tax;
	printf("\nMax On Peak Period  : ");
	scanf("%f",&mpeak);
	printf("Max Off Peak Period : ");
	scanf("%f",&moffpeak);
	printf("\nUsed Energy during On Peak Period  : ");
	scanf("%f",&peak);
	printf("Used Energy during Off Peak Period : ");
	scanf("%f",&offpeak);
	printf("              Used Reactive Power : ");
	scanf("%f",&mrp);
	printf("             Customer Used Energy : ");
	scanf("%f",&use);
	total=((mpeak+moffpeak)*peak)+((rp-1)*56.07);
	printf("       Section 1 Base Tariff\n");
	printf("       		Service Charge     %.2f   Baht\n",service);
	printf("       		Total Base Tariff  %.2f   Baht\n",total+service);
	printf("       Section 2 (Ft) Charge\n");
	eu=use*ft;
	printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
	tax = ((total+service)+eu)*7/100;
	printf("       Section 3 Tax 7%\n");
	printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
	bill=(total+service)+eu+tax;
	printf("       Total Electricity Charge          %.2f   Baht\n",bill);		
}
Temporary_Tariff()
{
	int Vol,y;
	float vat,de,use,total,service=312.24,eu,mpeak,moffpeak,mpp,mrp,tax;
	year(y);
	printf("\n");
	printf("             Customer Used Energy : ");	
	scanf("%f",&use);
	total=use*6.8025;
	printf("       Section 1 Base Tariff\n");
	printf("       		Service Charge     %.2f   Baht\n",service);
	printf("       		Total Base Tariff  %.2f   Baht\n",total+service);
	printf("       Section 2 (Ft) Charge\n");
	eu = use*ft;
	printf("            Used Energy x Ft Rate       %.2f   Baht\n",eu);
	printf("       Section 3 Tax 7%\n");
	tax = ((total+service)+eu)*7/100;
	printf("          (Base Tariff + Ft) x 7/100     %.2f   Baht\n",tax);
	bill=((total+service)+eu+tax);
	printf("       Total Electricity Charge          %.2f   Baht\n",bill);	
	
}
year()
{
	int m,y;
	printf("\nYear\n1.2022\n2.2023\n");
	printf("\nSelect Year : ");
	scanf("%d",&y);
	if(y==1){	
		printf("\n1.January\n2.February\n3.March\n4.April\n5.May\n6.June");
		printf("\n7.July\n8.August\n9.September\n10.October\n11.November\n12.December\n");
		printf("\nSelect Month : ");
		scanf("%d",&m);
		if(m<=4){
			mount(m);
			ft = 0.0139;
		}else if(m >= 5 && m <=8){
			mount(m);
			ft = 0.2477;				
		}else if(m >= 9 && m <=12){
			mount(m);
			ft = 0.9343;			
		}else{
			printf("Error");
		}
	}else if(y==2){
		printf("\n1.January\n2.February\n3.March\n4.April\n");			
		printf("\nSelect Month : ");
		scanf("%d",&m);
		if(m <=4 ){
			mount(m);
			ft = 0.0139;
		}
	}
	return ft;
}

float mount(int m)
{
	struct satang{
		float st1,st2,st3;
	};
	struct satang tang = {1.39,24.77,93.43};
	if(m<=4){
		
		printf("\n                             Ft    : %.2f Satang/kWh",tang.st1);
	}else if(m >= 5 && m <=8){
		
		printf("\n                             Ft    : %.2f Satang/kWh",tang.st2);
	}else if(m >= 9 && m <=12){
		
		printf("\n                             Ft    : %.2f Satang/kWh",tang.st3);	
	}else{
		printf("Error");
	}
}



