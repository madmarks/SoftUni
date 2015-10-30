#include <stdio.h>
#include <stdlib.h>

/*
 * Find online more information about ASCII (American Standard Code for 
 * Information Interchange) and write a program to prints the entire ASCII table
 * of characters at the console (characters from 0 to 255). Note that some 
 * characters have a special purpose and will not be displayed as expected. 
 * You may skip them or display them differently. 
 * You may need to use for-loops (learn in Internet how).
 * 
 * http://www.ascii-code.com/
 */
int main() 
{
    int i;
    
    printf("ASCII Table:\n\n");
    
    for(i=0; i<256; i++)
    {
        printf("0x%02x -> \'", i);
        
        switch(i)
        {
            case 0x00:
                printf("\\0\' NUL - Null char");
                break;
            case 0x01:
                printf("  \' SOH - Start of Heading");
                break;
            case 0x02:
                printf("  \' STX - Start of Text");
                break;
            case 0x03:
                printf("  \' ETX - End of Text");
                break;
            case 0x04:
                printf("  \' EOT - End of Transmission");
                break;
            case 0x05:
                printf("  \' ENQ - Enquiry");
                break;
            case 0x06:
                printf("  \' ACK - Acknowledgment");
                break;
            case 0x07:
                printf("\\a\' BEL - Alarm (Beep, Bell)");
                break;
            case 0x08:
                printf("\\b\' BS  - Backspace");
                break;
            case 0x09:
                printf("\\t\' HT  - Horizontal Tab");
                break;
            case 0x0A:
                printf("\\n\' LF  - Newline (Line Feed)");
                break;
            case 0x0B:
                printf("\\v\' VT  - Vertical Tab");
                break;
            case 0x0C:
                printf("\\f\' FF  - Formfeed");
                break;
            case 0x0D:
                printf("\\r\' CR  - Carriage Return");
                break;               
            case 0x0E:
                printf("  \' SO  - Shift Out / X-On");
                break;
            case 0x0F:
                printf("  \' SI  - Shift In / X-Off");
                break;                
            case 0x10:
                printf("  \' DLE - Data Line Escape");
                break;
            case 0x11:
                printf("  \' DC1 - Device Control 1 (oft. XON)");
                break;
            case 0x12:
                printf("  \' DC2 - Device Control 2");
                break;
            case 0x13:
                printf("  \' DC3 - Device Control 3 (oft. XOFF)");
                break;
            case 0x14:
                printf("  \' DC4 - Device Control 4");
                break;
            case 0x15:
                printf("  \' NAK - Negative Acknowledgement");
                break;
            case 0x16:
                printf("  \' SYN - Synchronous Idle");
                break;
            case 0x17:
                printf("  \' ETB - End of Transmit Block");
                break;
            case 0x18:
                printf("  \' CAN - Cancel");
                break;
            case 0x19:
                printf("  \' EM  - End of Medium");
                break;
            case 0x1A:
                printf("  \' SUB - Substitute");
                break;
            case 0x1B:
                printf("  \' ESC - Escape");
                break;
            case 0x1C:
                printf("  \' FS  - File Separator");
                break;
            case 0x1D:
                printf("  \' GS  - Group Separator");
                break;
            case 0x1E:
                printf("  \' RS  - Record Separator");
                break;
            case 0x1F:
                printf("  \' US  - Unit Separator");
                break;               
            default:
                printf("%c\'", i);
        }
        
        printf("\n");
    }
    
    return (EXIT_SUCCESS);
}

