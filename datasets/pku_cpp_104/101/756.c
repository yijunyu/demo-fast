/*
 *???????.cpp
 *?????
 *????: 2012-10-17
 *?????????????????????????
 */


int main(){
	int Aapp,Bapp,Capp,i;					//??A?B?C??????Aapp,Bapp,Capp?????i
	int Aw,Bw,Cw;							//??A?B?C?????Aw,Bw,Cw
    for (Aapp=1;Aapp<=3;Aapp++)				//?Aapp???1?3??
    {
    	for(Bapp=1;Bapp<=3;Bapp++)			//?Bapp???1?3??
    	{
    		for(Capp=1;Capp<=3;Capp++)		//?Capp???1?3??
    		{
    			Aw=(Bapp>Aapp)+(Capp==Aapp);	//A???
    			Bw=(Aapp>Bapp)+(Aapp>Capp);		//B???
    			Cw=(Capp>Bapp)+(Bapp>Aapp);		//C???
    			if (3-Aapp==Aw&&3-Bapp==Bw&&3-Capp==Cw)			//?????????????
    			{
    				for(i=0;i<=3;i++)			//?????3??0
    				{
    					if(Aapp==i)				//?A??==i?
    						cout<<"A";	//??"A"
    					if(Bapp==i)   			//?B??==i?
    						cout<<"B";	//??"B"
    					if(Capp==i)				//?C??==i?
    						cout<<"C";	//??"C"
    				}
    			}
       		}
    	}
    }
    return 0;									//????
}