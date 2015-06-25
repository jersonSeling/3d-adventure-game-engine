#include <math.h>
#include <stdio.h>

struct rendrInfo
{
   int xWin;
   int yWin;
   float xCenter;
   float yCenter;
   float camLenZ;
   float camEndZ;
   float fogBgnZ;
   float fogEndZ;
   float perspctv;
   int ortho;
   float **zIndex;
   int **scrnBuff;
};
typedef struct rendrInfo RENDRINFO;

int colorTransparency(int, int, float);

void aPix(float, float, float, int, struct rendrInfo);

void aPix(float x1, float y1, float z, int color, struct rendrInfo rI)
{
   int x, y;
   float x2, y2, transparence;
   int intX = (int)x1;
   int intY = (int)y1;
   
   x2 = 1 - (x1 - (float)intX);
   y2 = 1 - (y1 - (float)intY);
   x = (int)x1;
   y = (int)y1;
   transparence = 1 - x2 * y2;
   if ((x >= 0) && (x < rI.xWin) &&
       (y >= 0) && (y < rI.yWin))
   rI.scrnBuff[x][y] = colorTransparency(color, rI.scrnBuff[x][y], transparence);
   x2 = x1 - (float)intX;
   y2 = y1 - (float)intY;
   x = (int)x1 + 1;
   y = (int)y1 + 1;
   transparence = 1 - x2 * y2;
	if ((x >= 0) && (x < rI.xWin) &&
       (y >= 0) && (y < rI.yWin))
   rI.scrnBuff[x][y] = colorTransparency(color, rI.scrnBuff[x][y], transparence);
   x2 = x1 - (float)intX;
   y2 = 1 - (y1 - (float)intY);
   x = (int)x1 + 1;
   y = (int)y1;
   transparence = 1 - x2 * y2;
   if ((x >= 0) && (x < rI.xWin) &&
       (y >= 0) && (y < rI.yWin))
   rI.scrnBuff[x][y] = colorTransparency(color, rI.scrnBuff[x][y], transparence);
   x2 = 1 - (x1 - (float)intX);
   y2 = y1 - (float)intY;
   x = (int)x1;
   y = (int)y1 + 1;
   transparence = 1 - x2 * y2;
   if ((x >= 0) && (x < rI.xWin) &&
       (y >= 0) && (y < rI.yWin))
   rI.scrnBuff[x][y] = colorTransparency(color, rI.scrnBuff[x][y], transparence);
}

void aLine(float xA, float yA, float zA,
           float xB, float yB, float zB, int color, struct rendrInfo rI)
{
	int i, length;
   float x, y, z;
   float perspctvA, perspctvB;
   float xAB, yAB, zAB;

   if ((zA > rI.camLenZ) && (zB > rI.camLenZ))
   return;
   if ((zA < rI.camEndZ) && (zB < rI.camEndZ))
   return;

   if (zA > rI.camLenZ)
   {
      xA = xB - (rI.camLenZ - zB) / (zA - zB) * (xB - xA);
      yA = yB - (rI.camLenZ - zB) / (zA - zB) * (yB - yA);
      zA = rI.camLenZ;
   }
   if (zB > rI.camLenZ)
   {
      xB = xA - (rI.camLenZ - zA) / (zB - zA) * (xA - xB);
      yB = yA - (rI.camLenZ - zA) / (zB - zA) * (yA - yB);
      zB = rI.camLenZ;
   }

   if (zA < rI.camEndZ)
   {
      xA = xB - (zB - rI.camEndZ) / (zB - zA) * (xB - xA);
      yA = yB - (zB - rI.camEndZ) / (zB - zA) * (yB - yA);
      zA = rI.camEndZ;
   }
   if (zB < rI.camEndZ)
   {
      xB = xA - (zA - rI.camEndZ) / (zA - zB) * (xA - xB);
      yB = yA - (zA - rI.camEndZ) / (zA - zB) * (yA - yB);
      zB = rI.camEndZ;
   }

   if (!rI.ortho)
   {
      perspctvA = rI.perspctv / (rI.perspctv - zA);
      perspctvB = rI.perspctv / (rI.perspctv - zB);

      xA = xA * perspctvA;
      yA = yA * perspctvA;
      zA = zA * perspctvA;

      xB = xB * perspctvB;
      yB = yB * perspctvB;
      zB = zB * perspctvB;
   }

   xA = xA + rI.xCenter;
   yA = yA + rI.yCenter;
   xB = xB + rI.xCenter;
   yB = yB + rI.yCenter;

   if (xA < 0)
   {
      zA = zB - (xB - 0) / (xB - xA) * (zB - zA);
      yA = yB - (xB - 0) / (xB - xA) * (yB - yA);
      xA = 0;
   }
   if (xA >= rI.xWin)
   {
      zA = zB - (xB - rI.xWin) / (xB - xA) * (zB - zA);
      yA = yB - (xB - rI.xWin) / (xB - xA) * (yB - yA);
      xA = rI.xWin;
   }
   if (yA < 0)
   {
      zA = zB - (yB - 0) / (yB - yA) * (zB - zA);
      xA = xB - (yB - 0) / (yB - yA) * (xB - xA);
      yA = 0;
   }
   if (yA >= rI.yWin)
   {
      zA = zB - (yB - rI.yWin) / (yB - yA) * (zB - zA);
      xA = xB - (yB - rI.yWin) / (yB - yA) * (xB - xA);
      yA = rI.yWin;
   }

   if (xB < 0)
   {
      zB = zA - (xA - 0) / (xA - xB) * (zA - zB);
      yB = yA - (xA - 0) / (xA - xB) * (yA - yB);
      xB = 0;
   }
   if (xB >= rI.xWin)
   {
      zB = zA - (xA - rI.xWin) / (xA - xB) * (zA - zB);
      yB = yA - (xA - rI.xWin) / (xA - xB) * (yA - yB);
      xB = rI.xWin;
   }
   if (yB < 0)
   {
      zB = zA - (yA - 0) / (yA - yB) * (zA - zB);
      xB = xA - (yA - 0) / (yA - yB) * (xA - xB);
      yB = 0;
   }
   if (yB >= rI.yWin)
   {
      zB = zA - (yA - rI.yWin) / (yA - yB) * (zA - zB);
      xB = xA - (yA - rI.yWin) / (yA - yB) * (xA - xB);
      yB = rI.yWin;
   }

   if (fabs(round(xB) - round(xA)) > fabs(round(yB) - round(yA)))
   length = fabs(round(xB) - round(xA));
   else
   length = fabs(round(yB) - round(yA));
   
   xAB = (xB - xA) / length;
   yAB = (yB - yA) / length;
   zAB = (zB - zA) / length;

   for (i = 0; i <= length; i++)
   {
      x = xAB * i + xA;
      y = yAB * i + yA;
      z = zAB * i + zA;
      
      // I added "+0.001" to the zIndex because if I were
      // to draw a curve, the overlapping pixels on each
      // corner would make the curve look more spiky.
      if ((round(x) >= 0) && (round(x) < rI.xWin) &&
          (round(y) >= 0) && (round(y) < rI.yWin))
      if (z >= rI.zIndex[(int)round(x)][(int)round(y)]+0.001)
      {
         rI.zIndex[(int)round(x)][(int)round(y)] = z;
         aPix(x, y, z, color, rI);
      }
   }
}

void afLine(float xA, float yA, float zA,
            float xB, float yB, float zB, int color, int fogColor, struct rendrInfo rI)
{
	int i, length;
   float x, y, z;
   float perspctvA, perspctvB;
   float xAB, yAB, zAB;
   
   float fogBgnZ, fogEndZ;
   float zAFogAmt, zBFogAmt, zABFogAmt;
   float posInFog, fogLgth;
   float fogAmount;
   
   
   if ((zA > rI.camLenZ) && (zB > rI.camLenZ))
   return;
   if ((zA < rI.camEndZ) && (zB < rI.camEndZ))
   return;

   if (zA > rI.camLenZ)
   {
      xA = xB - (rI.camLenZ - zB) / (zA - zB) * (xB - xA);
      yA = yB - (rI.camLenZ - zB) / (zA - zB) * (yB - yA);
      zA = rI.camLenZ;
   }
   if (zB > rI.camLenZ)
   {
      xB = xA - (rI.camLenZ - zA) / (zB - zA) * (xA - xB);
      yB = yA - (rI.camLenZ - zA) / (zB - zA) * (yA - yB);
      zB = rI.camLenZ;
   }

   if (zA < rI.camEndZ)
   {
      xA = xB - (zB - rI.camEndZ) / (zB - zA) * (xB - xA);
      yA = yB - (zB - rI.camEndZ) / (zB - zA) * (yB - yA);
      zA = rI.camEndZ;
   }
   if (zB < rI.camEndZ)
   {
      xB = xA - (zA - rI.camEndZ) / (zA - zB) * (xA - xB);
      yB = yA - (zA - rI.camEndZ) / (zA - zB) * (yA - yB);
      zB = rI.camEndZ;
   }

   if (!rI.ortho)
   {
      perspctvA = rI.perspctv / (rI.perspctv - zA);
      perspctvB = rI.perspctv / (rI.perspctv - zB);

      xA = xA * perspctvA;
      yA = yA * perspctvA;
      zA = zA * perspctvA;

      xB = xB * perspctvB;
      yB = yB * perspctvB;
      zB = zB * perspctvB;
   }

   xA = xA + rI.xCenter;
   yA = yA + rI.yCenter;
   xB = xB + rI.xCenter;
   yB = yB + rI.yCenter;

   if (xA < 0)
   {
      zA = zB - (xB - 0) / (xB - xA) * (zB - zA);
      yA = yB - (xB - 0) / (xB - xA) * (yB - yA);
      xA = 0;
   }
   if (xA >= rI.xWin)
   {
      zA = zB - (xB - rI.xWin) / (xB - xA) * (zB - zA);
      yA = yB - (xB - rI.xWin) / (xB - xA) * (yB - yA);
      xA = rI.xWin;
   }
   if (yA < 0)
   {
      zA = zB - (yB - 0) / (yB - yA) * (zB - zA);
      xA = xB - (yB - 0) / (yB - yA) * (xB - xA);
      yA = 0;
   }
   if (yA >= rI.yWin)
   {
      zA = zB - (yB - rI.yWin) / (yB - yA) * (zB - zA);
      xA = xB - (yB - rI.yWin) / (yB - yA) * (xB - xA);
      yA = rI.yWin;
   }

   if (xB < 0)
   {
      zB = zA - (xA - 0) / (xA - xB) * (zA - zB);
      yB = yA - (xA - 0) / (xA - xB) * (yA - yB);
      xB = 0;
   }
   if (xB >= rI.xWin)
   {
      zB = zA - (xA - rI.xWin) / (xA - xB) * (zA - zB);
      yB = yA - (xA - rI.xWin) / (xA - xB) * (yA - yB);
      xB = rI.xWin;
   }
   if (yB < 0)
   {
      zB = zA - (yA - 0) / (yA - yB) * (zA - zB);
      xB = xA - (yA - 0) / (yA - yB) * (xA - xB);
      yB = 0;
   }
   if (yB >= rI.yWin)
   {
      zB = zA - (yA - rI.yWin) / (yA - yB) * (zA - zB);
      xB = xA - (yA - rI.yWin) / (yA - yB) * (xA - xB);
      yB = rI.yWin;
   }

   if (fabs(round(xB) - round(xA)) > fabs(round(yB) - round(yA)))
   length = fabs(round(xB) - round(xA));
   else
   length = fabs(round(yB) - round(yA));
   
   xAB = (xB - xA) / length;
   yAB = (yB - yA) / length;
   zAB = (zB - zA) / length;

   
   fogBgnZ = rI.fogBgnZ;
   fogEndZ = rI.fogEndZ;
   
   if (!rI.ortho)
   {
      fogBgnZ = rI.fogBgnZ * perspctvA;
      fogEndZ = rI.fogEndZ * perspctvA;
   }
   fogLgth = fogBgnZ - fogEndZ;
   posInFog = zA - fogEndZ;
   zAFogAmt = 1 - posInFog / fogLgth;
   
   if (zA > rI.fogBgnZ)
      zAFogAmt = 0;
   if (zA <= rI.fogEndZ)
      zAFogAmt = 1;
   
   if (!rI.ortho)
   {
      fogBgnZ = rI.fogBgnZ * perspctvB;
      fogEndZ = rI.fogEndZ * perspctvB;
   }
   fogLgth = fogBgnZ - fogEndZ;
   posInFog = zB - fogEndZ;
   zBFogAmt = 1 - posInFog / fogLgth;
   
   if (zB > rI.fogBgnZ)
      zBFogAmt = 0;
   if (zB <= rI.fogEndZ)
      zBFogAmt = 1;
   
   zABFogAmt = (zBFogAmt - zAFogAmt) / length;
   
   
   for (i = 0; i <= length; i++)
   {
      x = xAB * i + xA;
      y = yAB * i + yA;
      z = zAB * i + zA;
      
      fogAmount = zABFogAmt * i + zAFogAmt;
      
      // I added "+0.001" to the zIndex because if I were
      // to draw a curve, the overlapping pixels on each
      // corner would make the curve look more spiky.
      if ((round(x) >= 0) && (round(x) < rI.xWin) &&
          (round(y) >= 0) && (round(y) < rI.yWin))
      if (z >= rI.zIndex[(int)round(x)][(int)round(y)]+0.001)
      {
         rI.zIndex[(int)round(x)][(int)round(y)] = z;
         aPix(x, y, z, colorTransparency(color, fogColor, fogAmount), rI);
      }
   }
}
