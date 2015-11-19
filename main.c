#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct _SinWaveData{
	float* Data;
	float* Time;
	float Amplitude;
	float Freq;
	float Length;
	float SampleFreq;
} _SinWaveData;

#define PI 3.1415926

void CreateSineWave(_SinWaveData* SinWaveData)
{
	int DataLength, i;
	DataLength = (SinWaveData->Length * SinWaveData->SampleFreq);
	float Data[DataLength];
	float Time[DataLength];
		
	for(i = 0;i < (int)DataLength;i++)
	{
		Time[i] = (float)i / DataLength; 
		Data[i] = SinWaveData->Amplitude * sin(2 * PI * SinWaveData->Freq * Time[i]);
	}
	SinWaveData->Data = Data;
	SinWaveData->Time = Time;
}



int main(void){
	
	_SinWaveData SinWaveData;
	SinWaveData.Amplitude = 1.0;
	SinWaveData.Freq = 500.0;
	SinWaveData.Length = 1.0;
	SinWaveData.SampleFreq = 100000.0;
	
	int i;

	FILE *fp;
	
	CreateSineWave(&SinWaveData);

	if((fp = fopen("data.dat", "w+")) == NULL)
	{
		printf("fail to cat shell\n");
		return EXIT_FAILURE;
	}
	
	for(i = 0;i < 200;i++)
	{
		fprintf(fp, "%f, %f \n", SinWaveData.Time[i], SinWaveData.Data[i] );
	}


	fclose(fp);
}
